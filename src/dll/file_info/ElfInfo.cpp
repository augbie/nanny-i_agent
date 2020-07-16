/*
 * Copyright (C) 2020-2025 ASHINi corp. 
 * 
 * This library is free software; you can redistribute it and/or 
 * modify it under the terms of the GNU Lesser General Public 
 * License as published by the Free Software Foundation; either 
 * version 2.1 of the License, or (at your option) any later version. 
 * 
 * This library is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU 
 * Lesser General Public License for more details. 
 * 
 * You should have received a copy of the GNU Lesser General Public 
 * License along with this library; if not, write to the Free Software 
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA 
 * 
 */

#include "stdafx.h"
#include "com_struct.h"
#include "ElfInfo.h"


CELFInfo::CELFInfo(char *pcFile)
{
	m_nFd = -1;
	m_nElfClass = ASI_FI_ELF_CLASS_NONE;
	memset(&m_stElfHeader, 0, sizeof(m_stElfHeader));
	memset(&m_stElfHeader64, 0, sizeof(m_stElfHeader64));
	if(pcFile != NULL)
	{
		Open(pcFile);
	}
}

CELFInfo::~CELFInfo()
{
	Close();
}

BOOL CELFInfo::IsELF()
{
	if(!_strnicmp((char*)m_stElfHeader.e_ident, "\177ELF", 4))
	{
		return TRUE;
	}
	return FALSE;
}

BOOL CELFInfo::IsELF64()
{
	if(!_strnicmp((char*)m_stElfHeader64.e_ident, "\177ELF", 4))
	{
		return TRUE;
	}
	return FALSE;
}


INT32 CELFInfo::ReadElfHdr()
{
	INT32 nRetVal = 0;
	INT32 nValue = 0;
	if(m_nFd == -1)
		return -1;

	do{
		nValue = (INT32)lseek(m_nFd, (off_t)0, SEEK_SET);
		if(nValue != 0)
		{
			nRetVal = -2;
			break;
		}

		nValue = (INT32)read(m_nFd, (void *)&m_stElfHeader, sizeof(m_stElfHeader));
		if(nValue != sizeof(m_stElfHeader))
		{
			nRetVal = -3;
			break;
		}

		if(Is64Bit() == TRUE)
		{
			nRetVal = ReadElfHdr64();
			if(nRetVal != 0)
			{
				nRetVal -= 10;
				break;
			}
			if(IsELF64() == FALSE)
			{
				nRetVal = -5;
				break;
			}			
		}
		else
		{
			if(IsELF() == FALSE)
			{
				nRetVal = -5;
				break;
			}
		}
		nRetVal = 0;
	}while(FALSE);
		
	return nRetVal;
}

INT32 CELFInfo::ReadElfHdr64()
{
	INT32 nRetVal = 0;
	if(m_nFd == -1)
		return -1;

	nRetVal = (INT32)lseek(m_nFd, (off_t)0, SEEK_SET);
	if(nRetVal != 0)
		return -2;

	nRetVal = read(m_nFd, (void *)&m_stElfHeader64, sizeof(m_stElfHeader64));
	if(nRetVal != sizeof(m_stElfHeader64))
		return -3;

	return 0;
}


INT32 CELFInfo::Open(char *pcFilePath)
{
	INT32 nRetVal = 0;
	
	if(m_nFd != -1)
		return 0;
	
	if(pcFilePath == NULL || pcFilePath[0] == 0)
		return -1;

	do{
		m_nFd = open(pcFilePath, O_RDONLY|O_SYNC);
		if(m_nFd < 0)
		{
			m_nFd = -1;
			nRetVal = -2;
			break;
		}
		nRetVal = ReadElfHdr();
		if(nRetVal != 0)
		{
			nRetVal -= 100;
			break;
		}
		nRetVal = 0;
	}while(FALSE);

	if(nRetVal != 0)
	{
		Close();
	}
	return nRetVal;
}

VOID CELFInfo::Close()
{
	if(m_nFd != -1)
	{
		close(m_nFd);
		memset(&m_stElfHeader, 0, sizeof(m_stElfHeader));
		memset(&m_stElfHeader64, 0, sizeof(m_stElfHeader64));
		m_nFd = -1;
		m_nElfClass = ASI_FI_ELF_CLASS_NONE;
	}
}

INT32 CELFInfo::GetMachineType()
{
	WORD wMachine = ET_NONE;
	INT32 nMachineType = ASI_FI_ELF_MACHINE_NONE;

	if(m_nElfClass == ASI_FI_ELF_CLASS_32BIT)
		wMachine = m_stElfHeader.e_machine;
	else if(m_nElfClass == ASI_FI_ELF_CLASS_64BIT)
		wMachine = m_stElfHeader64.e_machine;
		
	switch(wMachine)
	{
		case EM_NONE:
			nMachineType = ASI_FI_ELF_MACHINE_NONE;
			break;
		case EM_386:
			nMachineType = ASI_FI_ELF_MACHINE_386;
			break;
		case EM_X86_64:
			nMachineType = ASI_FI_ELF_MACHINE_X86_64;
			break;
		case EM_AARCH64:
			nMachineType = ASI_FI_ELF_MACHINE_AARCH64;
			break;
		default:
			nMachineType = ASI_FI_ELF_MACHINE_NONE;
			break;
	}
	return nMachineType;

}

INT32	CELFInfo::GetFileElfType()
{
	WORD wEType = ET_NONE;
	INT32 nElfType = ASI_FI_ELF_TYPE_NONE;

	if(m_nElfClass == ASI_FI_ELF_CLASS_32BIT)
		wEType = m_stElfHeader.e_type;
	else if(m_nElfClass == ASI_FI_ELF_CLASS_64BIT)
		wEType = m_stElfHeader64.e_type;
		
	switch(wEType)
	{
		case ET_NONE:
			nElfType = ASI_FI_ELF_TYPE_NONE;
			break;
		case ET_REL:
			nElfType = ASI_FI_ELF_TYPE_DRV;
			break;
		case ET_EXEC:
			nElfType = ASI_FI_ELF_TYPE_EXE;
			break;
		case ET_DYN:
			nElfType = ASI_FI_ELF_TYPE_SO;
			break;
		default:
			nElfType = ASI_FI_ELF_TYPE_NONE;
			break;
	}
	return nElfType;
}

VOID CELFInfo::GetFileElfTypeString(char *pcElfType, INT32 nLength)
{
	WORD wEType = ET_NONE;
	INT32 nElfType = ASI_FI_ELF_TYPE_NONE;

	if(pcElfType == NULL || nLength < 1)
		return;

	if(m_nElfClass == ASI_FI_ELF_CLASS_32BIT)
		wEType = m_stElfHeader.e_type;
	else if(m_nElfClass == ASI_FI_ELF_CLASS_64BIT)
		wEType = m_stElfHeader64.e_type;

	if(wEType == ET_EXEC)
	{
		strncpy(pcElfType, "executable file", nLength-1);
	}
	else if(wEType == ET_REL)
	{
		strncpy(pcElfType, "relocatable file", nLength-1);
	}
	else if(wEType == ET_DYN)
	{
		strncpy(pcElfType, "shared objec file", nLength-1);
	}
	else
	{
		strncpy(pcElfType, "unknown file", nLength-1);
	}	
}

VOID CELFInfo::GetFileElfAbiString(char *pcElfAbi, INT32 nLength)
{
	BYTE bOSAbi = 0;

	if(pcElfAbi == NULL || nLength < 1)
		return;
	
	if(m_nElfClass == ASI_FI_ELF_CLASS_32BIT)
		bOSAbi = m_stElfHeader.e_ident[EI_OSABI];
	else if(m_nElfClass == ASI_FI_ELF_CLASS_64BIT)
		bOSAbi = m_stElfHeader64.e_ident[EI_OSABI];
	
	switch(bOSAbi)
	{
		case ELFOSABI_SYSV:
			strncpy(pcElfAbi, "UNIX System V", nLength-1);
			break;

		case ELFOSABI_HPUX:
			strncpy(pcElfAbi, "HP-UX", nLength-1);
			break;

		case ELFOSABI_NETBSD:
			strncpy(pcElfAbi, "NetBSD", nLength-1);
			break;

		case ELFOSABI_LINUX:
			strncpy(pcElfAbi, "Linux", nLength-1);
			break;

		case ELFOSABI_SOLARIS:
			strncpy(pcElfAbi, "Sun Solaris", nLength-1);
			break;

		case ELFOSABI_AIX:
			strncpy(pcElfAbi, "IBM AIX", nLength-1);
			break;

		case ELFOSABI_IRIX:
			strncpy(pcElfAbi, "SGI Irix", nLength-1);
			break;

		case ELFOSABI_FREEBSD:
			strncpy(pcElfAbi, "FreeBSD", nLength-1);
			break;

		case ELFOSABI_TRU64:
			strncpy(pcElfAbi, "Compaq TRU64 UNIX", nLength-1);
			break;

		case ELFOSABI_MODESTO:
			strncpy(pcElfAbi, "Novell Modesto", nLength-1);
			break;

		case ELFOSABI_OPENBSD:
			strncpy(pcElfAbi, "OpenBSD", nLength-1);
			break;

		case ELFOSABI_ARM_AEABI:
			strncpy(pcElfAbi, "ARM EABI", nLength-1);
			break;

		case ELFOSABI_ARM:
			strncpy(pcElfAbi, "ARM", nLength-1);
			break;

		case ELFOSABI_STANDALONE:
			strncpy(pcElfAbi, "Standalone", nLength-1);
			break;

		default:
			strncpy(pcElfAbi, "Unknown", nLength-1);
			break;
	}
}

VOID CELFInfo::GetFileElfEntryPointString(char *pcEntryPoint, INT32 nLength)
{
	if(pcEntryPoint == NULL || nLength < 1)
		return;
	
	if(m_nElfClass == ASI_FI_ELF_CLASS_32BIT)
	{
		snprintf(pcEntryPoint, nLength-1, "%08lx", m_stElfHeader.e_entry);	
	}
	else if(m_nElfClass == ASI_FI_ELF_CLASS_64BIT)
	{
		snprintf(pcEntryPoint, nLength-1, "%08lx", m_stElfHeader64.e_entry);	
	}
}

BOOL CELFInfo::Is64Bit()
{
	if (m_stElfHeader.e_ident[EI_CLASS] == ELFCLASS64)
	{
		m_nElfClass = ASI_FI_ELF_CLASS_64BIT;
		return TRUE;
	}
	m_nElfClass = ASI_FI_ELF_CLASS_32BIT;
	return FALSE;
}

