/*
 * Rufus: The Reliable USB Formatting Utility
 * Drive access function calls
 * Copyright © 2011-2014 Pete Batard <pete@akeo.ie>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <windows.h>
#include <stdint.h>

#pragma once

#define RUFUS_EXTRA_PARTITION_TYPE	0xea

char* GetPhysicalName(DWORD DriveIndex);
HANDLE GetPhysicalHandle(DWORD DriveIndex, BOOL bWriteAccess, BOOL bLockDrive);
char* GetLogicalName(DWORD DriveIndex, BOOL bKeepTrailingBackslash, BOOL bSilent);
BOOL WaitForLogical(DWORD DriveIndex);
HANDLE GetLogicalHandle(DWORD DriveIndex, BOOL bWriteAccess, BOOL bLockDrive);
BOOL GetDriveLetters(DWORD DriveIndex, char* drive_letters);
UINT GetDriveTypeFromIndex(DWORD DriveIndex);
char GetUnusedDriveLetter(void);
BOOL GetDriveLabel(DWORD DriveIndex, char* letter, char** label);
uint64_t GetDriveSize(DWORD DriveIndex);
BOOL IsMediaPresent(DWORD DriveIndex);
BOOL AnalyzeMBR(HANDLE hPhysicalDrive, const char* TargetName);
BOOL AnalyzePBR(HANDLE hLogicalVolume);
int GetDrivePartitionData(DWORD DriveIndex, char* FileSystemName, DWORD FileSystemNameSize);
BOOL UnmountVolume(HANDLE hDrive);
BOOL MountVolume(char* drive_name, char *drive_guid);
BOOL RemountVolume(char* drive_name);
BOOL CreatePartition(HANDLE hDrive, int partition_style, int file_system, BOOL mbr_uefi_marker);
BOOL DeletePartitions(HANDLE hDrive);
const char* GetPartitionType(BYTE Type);
