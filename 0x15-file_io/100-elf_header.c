#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void verify_elf(unsigned char *e);
void magic_elf(unsigned char *e);
void class_elf(unsigned char *e);
void data_elf(unsigned char *e);
void version_elf(unsigned char *e);
void abi_elf(unsigned char *e);
void osabi_elf(unsigned char *e);
void type_elf(unsigned int e_type, unsigned char *e);
void entry_elf(unsigned long int e_entry, unsigned char *e);
void close_elf(int fd_elf);

/**
 * verify_elf - a function that verifies if a file is an ELF file.
 * @e: A pointer to an ELF struct
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void verify_elf(unsigned char *e)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e[index] != 127 &&
		    e[index] != 'E' &&
		    e[index] != 'L' &&
		    e[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * magic_elf - a function that prints the magic numbers of an ELF file
 * @e: A pointer to an ELF struct
 *
 * Description: Magic numbers are separated by spaces.
 */
void magic_elf(unsigned char *e)
{
	int index;

	printf("  Magic:          ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * class_elf - a function that prints the class of an ELF file
 * @e: A pointer to an ELF struct
 */
void class_elf(unsigned char *e)
{
	printf("  Class:           ");

	switch (e[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e[EI_CLASS]);
	}
}

/**
 * data_elf - a function that prints the data of an ELF file
 * @e: A pointer to an ELF file
 */
void data_elf(unsigned char *e)
{
	printf(" Data:           ");

	switch (e[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e[EI_CLASS]);
	}
}

/**
 * version_elf - a function that prints the version of an ELF file
 * @e: A pointer to an ELF struct
 */
void version_elf(unsigned char *e)
{
	printf("  Version: %d",           e[EI_VERSION]);

	switch (e[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * osabi_elf - a function that prints the OS/ABI of an ELF file
 * @e: A pointer to an ELF version.
 */
void osabi_elf(unsigned char *e)
{
	printf(" OS/ABI:           ");

	switch (e[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e[EI_OSABI]);
	}
}

/**
 * abi_elf - a function that prints the ABI version of an ELF file
 * @e: A pointer to an ELF ABI version.
 */
void abi_elf(unsigned char *e)
{
	printf("  ABI Version:           %d\n", e[EI_ABIVERSION]);
}

/**
 * type_elf - a function that prints the type of an ELF file.
 * @e_type: The ELF type.
 * @e: A pointer to an ELF struct
 */
void type_elf(unsigned int e_type, unsigned char *e)
{
	if (e[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf(" Type:          ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * entry_elf - a function that prints the entry point of an ELF file
 * @e_entry: The address of the ELF entry point.
 * @e: A pointer to an ELF struct
 */
void entry_elf(unsigned long int e_entry, unsigned char *e)
{
	printf("Entry point address:          ");

	if (e[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Closes an ELF file.
 * @fd_elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int fd_elf)
{
	if (close(fd_elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_elf);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *file;
	int opn, rd;

	opn = open(argv[1], O_RDONLY);
	if (opn == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	file = malloc(sizeof(Elf64_Ehdr));
	if (file == NULL)
	{
		close_elf(opn);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	rd = read(opn, file, sizeof(Elf64_Ehdr));
	if (rd == -1)
	{
		free(file);
		close_elf(opn);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	verify_elf(file->e);
	printf("ELF Header:\n");
	magic_elf(file->e);
	class_elf(file->e);
	data_elf(file->e);
	version_elf(file->e);
	osabi_elf(file->e);
	abi_elf(file->e);
	type_elf(file->e_type, file->e);
	entry_elf(file->e_entry, file->e);

	free(file);
	close_elf(opn);
	return (0);
}
