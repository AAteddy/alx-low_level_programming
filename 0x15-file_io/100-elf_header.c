#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void verify_elf(unsigned char *elf);
void magic_elf(unsigned char *elf);
void class_elf(unsigned char *elf);
void data_elf(unsigned char *elf);
void version_elf(unsigned char *elf);
void abi_elf(unsigned char *elf);
void osabi_elf(unsigned char *elf);
void type_elf(unsigned int elf_type, unsigned char *elf);
void entry_elf(unsigned long int elf_entry, unsigned char *elf);
void close_elf(int fd_elf);

/**
 * verify_elf - verifies if a file is an ELF file.
 * @elf: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void verify_elf(unsigned char *elf)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (elf[index] != 127 &&
		    elf[index] != 'E' &&
		    elf[index] != 'L' &&
		    elf[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * magic_elf - Prints the magic numbers of an ELF header.
 * @elf: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void magic_elf(unsigned char *elf)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", elf[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * class_elf - Prints the class of an ELF header.
 * @elf: A pointer to an array containing the ELF class.
 */
void class_elf(unsigned char *elf)
{
	printf("  Class: ");

	switch (elf[EI_CLASS])
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
		printf("<unknown: %x>\n", elf[EI_CLASS]);
	}
}

/**
 * data_elf - Prints the data of an ELF header.
 * @elf: A pointer to an array containing the ELF class.
 */
void data_elf(unsigned char *elf)
{
	printf("  Data: ");

	switch (elf[EI_DATA])
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
		printf("<unknown: %x>\n", elf[EI_CLASS]);
	}
}

/**
 * version_elf - Prints the version of an ELF header.
 * @elf: A pointer to an array containing the ELF version.
 */
void version_elf(unsigned char *elf)
{
	printf("  Version: %d", elf[EI_VERSION]);

	switch (elf[EI_VERSION])
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
 * osabi_elf - Prints the OS/ABI of an ELF header.
 * @elf: A pointer to an array containing the ELF version.
 */
void osabi_elf(unsigned char *elf)
{
	printf("  OS/ABI: ");

	switch (elf[EI_OSABI])
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
		printf("<unknown: %x>\n", elf[EI_OSABI]);
	}
}

/**
 * abi_elf - Prints the ABI version of an ELF header.
 * @elf: A pointer to an array containing the ELF ABI version.
 */
void abi_elf(unsigned char *elf)
{
	printf("  ABI Version: %d\n", elf[EI_ABIVERSION]);
}

/**
 * type_elf - Prints the type of an ELF header.
 * @elf_type: The ELF type.
 * @elf: A pointer to an array containing the ELF class.
 */
void type_elf(unsigned int elf_type, unsigned char *elf)
{
	if (elf[EI_DATA] == ELFDATA2MSB)
		elf_type >>= 8;

	printf("  Type: ");

	switch (elf_type)
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
		printf("<unknown: %x>\n", elf_type);
	}
}

/**
 * entry_elf - Prints the entry point of an ELF header.
 * @elf_entry: The address of the ELF entry point.
 * @elf: A pointer to an array containing the ELF class.
 */
void entry_elf(unsigned long int elf_entry, unsigned char *elf)
{
	printf("  Entry point address: ");

	if (elf[EI_DATA] == ELFDATA2MSB)
	{
		elf_entry = ((elf_entry << 8) & 0xFF00FF00) |
			  ((elf_entry >> 8) & 0xFF00FF);
		elf_entry = (elf_entry << 16) | (elf_entry >> 16);
	}

	if (elf[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)elf_entry);

	else
		printf("%#lx\n", elf_entry);
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
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
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

	verify_elf(file->elf);
	printf("ELF Header:\n");
	magic_elf(file->elf);
	class_elf(file->elf);
	data_elf(file->elf);
	version_elf(file->elf);
	osabi_elf(file->elf);
	abi_elf(file->elf);
	type_elf(file->elf_type, file->elf);
	entry_elf(file->elf_entry, file->elf);

	free(file);
	close_elf(opn);
	return (0);
}
