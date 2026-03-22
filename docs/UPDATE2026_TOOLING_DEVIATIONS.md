# UPDATE2026_TOOLING_DEVIATIONS

## Purpose

This document records the tooling deviations that apply specifically to the first update-2026 comparison run and explains why the run-local build/test harness was changed after the initial failed attempt.

## Root-cause analysis of the original blocker

The original `first_update2026_run` failed during configure/build because its run-local generated CMake file used a live GoogleTest `FetchContent` URL.

The specific issue was not the frozen prompt package or the frozen source-under-test. The issue was that the run-local generated test harness still embedded a remote dependency acquisition step:

- `FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip)`
- `FetchContent_MakeAvailable(googletest)`

In this environment, the GitHub archive request is blocked by the configured proxy, which returns `HTTP/1.1 403 Forbidden`.

## Why this was a tooling inconsistency

The scientific inputs for the run were already frozen correctly:
- prompt package unchanged;
- source under test unchanged; and
- preserved raw generation output unchanged.

The inconsistency was that the update-2026 run-local harness was still using the earlier remote dependency template instead of the repository-local provider/shim strategy expected for current controlled offline execution.

## Local provider / shim strategy now used

The corrected run uses a repository-local GoogleTest-compatible shim path made of:

1. `cmake/LocalGTest.cmake`
   - defines the local helper targets and aliases;
2. `third_party/gtest_shim/include/gtest/gtest.h`
   - provides the minimal GoogleTest-compatible macro surface required by the preserved generated test file; and
3. `third_party/gtest_shim/src/gtest_shim.cpp` and `third_party/gtest_shim/src/gtest_shim_main.cpp`
   - provide test registration, assertion reporting, and a main entrypoint.

The generated test target is registered directly with CTest through the helper instead of through remote GoogleTest discovery.

## Scope of the deviation

This deviation affects **tooling only**:
- dependency provisioning;
- test harness implementation; and
- test registration/execution plumbing.

This deviation does **not** alter:
- prompt wording;
- prompt rendering;
- raw model output;
- generated test source content; or
- source-under-test semantics.

## Observed outcome after applying the local strategy

After replacing the remote dependency path with the local helper/shim path:
- configure succeeded;
- build succeeded; and
- the preserved generated test suite executed under CTest.

The executable outcome is therefore now available for the run, and the remaining blocked dimension is coverage only.

## Remaining open tooling limitation

Coverage remains unavailable because `gcovr` is not installed in this environment.

No alternate coverage tool was substituted for this run, so the absence of coverage remains explicit and auditable rather than silently normalized away.
