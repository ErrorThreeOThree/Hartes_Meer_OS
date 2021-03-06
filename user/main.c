#include "my_io.h"
#include "syscalls.h"
#include "counter.h"

#define GPIO_OFFSET (0x3F000000)
#define UART_BASE (0x7E201000 - GPIO_OFFSET)

void print_ship(int v1, int v2);

int main() {
	print_ship(0, 8);
	char c;
	while (1) {
		c = sys_read_char();
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			printf("got char %c, spawning new process..\n", c);
			sys_create_thread(new_process, &c, 1 ,1);
		} else {
			printf("%c ist kein Buchstabe!\n", c);
		}
	}
}




void print_ship(int v1, int v2) {

		char *boat = "\n"
					"                                   ||`-.___\n"
							"                                   ||    _.>\n"
									"                                   ||_.-'\n"
											"               ==========================================\n"
													"                `.:::::::.       `:::::::.       `:::::::.\n"
															"                  \\:::::::.        :::::::.        :::::::\\\n"
																	"                   L:::::::         :::::::         :::::::L\n"
																			"                   J::::::::        ::::::::        :::::::J\n"
																					"                    F:::::::        ::::::::        ::::::::L\n"
																							"                    |:::::::        ::::::::        ::::::::|\n"
																									"                    |:::::::        ::::::::        ::::::::|     .---.\n"
																											"                    |:::::::        ::::::::        ::::::::|    /(@  o`.\n"
																													"                    |:::::::        ::::::::        ::::::::|   |    /^^^\n"
																															"     __             |:::::::        ::::::::        ::::::::|    \\ . \\vvv\n"
																																	"   .'_ \\            |:::::::        ::::::::        ::::::::|     \\ `--'\n"
																																			"   (( ) |           |:::::::        ::::::::        ::::::::|      \\ `.\n"
																																					"    `/ /            |:::::::        ::::::::        ::::::::|       L  \\\n"
																																							"    / /             |:::::::        ::::::::        ::::::::|       |   \\\n"
																																									"   J J              |:::::::        ::::::::        ::::::::|       |    L\n"
																																											"   | |              |:::::::        ::::::::        ::::::::|       |    |\n"
																																													"   | |              |:::::::        ::::::::        ::::::::|       F    |\n"
																																															"   | J\\             F:::::::        ::::::::        ::::::::F      /     |\n"
																																																	"   |  L\\           J::::::::       .::::::::       .:::::::J      /      F\n"
																																																			"   J  J `.     .   F:::::::        ::::::::        ::::::::F    .'      J\n"
																																																					"    L  \\  `.  //  /:::::::'      .::::::::'      .::::::::/   .'        F\n"
																																																							"    J   `.  `//_..---.   .---.   .---.   .---.   .---.   <---<         J\n"
																																																									"     L    `-//_=/  _  \\=/  _  \\=/  _  \\=/  _  \\=/  _  \\=/  _  \\       /\n"
																																																											"     J     /|  |  (_)  |  (_)  |  (_)  |  (_)  |  (_)  |  (_)  |     /\n"
																																																													"      \\   / |   \\     //\\     //\\     //\\     //\\     //\\     /    .'\n"
																																																															"       \\ / /     `---//  `---//  `---//  `---//  `---//  `---'   .'\n"
																																																																	"________/_/_________//______//______//______//______//_________.'_________\n"
																																																																			"##########################################################################";
			printf("%s\n\n\t Welcome to Hartes Meer OS V%i.%i, ALL ABOARD!!! YAHAR!!!!\n\n", boat, v1, v2);
}
