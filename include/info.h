#ifndef INFO_H
#define INFO_H

/** @file info.h
 * @brief Build information.
 *
 * Update the build information each compilation with CMake.
 *
 * Depends on commands cmake, git, and date.
 */

#include <stdint.h>

/** @brief Human readable commit description.
 *
 * String based on the latest tag, the number of commits, and uncommitted
 * changes.
 *
 * Examples:
 *
 * - Tag v1.2
 *   - "v1.2"
 * - Tag v1.2, + 3 commits, commit 456789a
 *   - "v1.2-3-g456789a"
 * - Tag v1.2, + 3 commits, commit 456789a, uncommitted changes
 *   - "v1.2-3-g456789a-dirty"
 */
extern const char git_commit_describe[];

/** @brief Commit hash.
 *
 * String with full commit hash and uncommitted changes.
 *
 * Examples:
 *
 * - Commit
 *   - "112233445566778899aabbccddeeff0011223344"
 * - Commit, uncommitted changes
 *   - "112233445566778899aabbccddeeff0011223344-dirty"
 */
extern const char git_commit_hash[];

/** @brief Build type.
 *
 * Build type provided to CMake with CMAKE_BUILD_TYPE.
 * Can be any string.
 *
 * Examples:
 *
 * - "" (Empty)
 * - "Debug"
 * - "Release"
 * - "MinSizeRel" (Minimum Size Release)
 * - "RelWithDebInfo" (Release With Debug Info)
 */
extern const char build_type[];

/** @brief Username and host used to build.
 *
 * Formatted as USER@HOST.
 *
 * Example: "john@workstation"
 */
extern const char build_user[];

/** @brief Build date (local time).
 *
 * Formatted as YYYY-mm-dd HH:MM:SS +TZ.
 *
 * Example: "2022-12-31 23:59:59 +0000"
 */
extern const char build_date[];

/** @brief Build Unix time (UTC).
 *
 * Seconds since the epoch (1970-01-01 00:00:00 +0000).
 *
 * Example: 1672531199
 */
extern const uint64_t build_time;

#endif /* INFO_H */
