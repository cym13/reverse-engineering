/* Keygen for http://crackmes.de/users/twistedtux/first_keygenme/
 *
 * LICENSE
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 *  END_OF_LICENSE
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* login l    ; key = dchEks */
/* login truc ; key = keEGht */

int main(int argc, char *argv[])
{
    /*
    if (argc != 3) {
        printf("Utilisation : %s [pseudo] [clef]\n", argv[0]);
        return 1;
    }
    */

    if (argc != 2) {
        printf("Utilisation : %s [pseudo]\n", argv[0]);
        return 1;
    }

    char* login  = argv[1];
    char* key    = argv[2];
    char  kstr[] = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

    /*
    if ( strlen(key) == 6 )
    if ( kstr[ f1(login) ] == key[0] )
    if ( kstr[ f2(login) ] == key[1] )
    if ( kstr[ f3(login) ] == key[2] )
    if ( kstr[ f4(login) ] == key[3] )
    if ( kstr[ f5(login) ] == key[4] )
    if ( kstr[ f6(login) ] == key[5] ) {
        printf("Bravo !!\n");
        return 0;
    }
    return 1;
    */

    printf("%c", kstr[ f1(login) ]);
    printf("%c", kstr[ f2(login) ]);
    printf("%c", kstr[ f3(login) ]);
    printf("%c", kstr[ f4(login) ]);
    printf("%c", kstr[ f5(login) ]);
    printf("%c", kstr[ f6(login) ]);
    printf("\n");
}

/* fcn.080485cd */
int f1(char login[])
{
    return ((strlen(login) & 0xff) ^ 0x3b) & 0x3f;  // result < 128
}

/* fcn.080485e3 */
int f2(char login[])
{
    int n = strlen(login);
    int result = 0;

    while (n-- >= 0)
        result += (login[n] & 0xff);

    return (result ^ 0x4f) & 0x3f;
}

/* fcn.0804861a */
int f3(char login[])
{
    int n      = strlen(login);
    int result = 1;

    while (--n >= 0) {
        result *= ((*login++) & 0xff);
        result &= 0xff;
    }

    return (result ^ 0x55) & 0x3f;
}

/* fcn.08048650 */
int f4(char login[])
{
    int n = strlen(login);
    int tmp = login[0];
    char* log = login;

    while (--n >= 0) {
        if ((unsigned int)*++login > (unsigned int)tmp) {
            tmp = (int)*login;
        }
    }

    tmp ^= 0xe;
    srand((unsigned int) tmp);

    return rand() & 0x3f;
}

/* fcn.08048708 */
int f5_bis(char l, int r, int n)
{
    int result = 1;
    int tmp = 2;

    if (tmp == 0)
        return 1;

    while (tmp--) {
        result *= l;
    }

    return result;
}

/* fcn.0804868e */
int f5(char login[])
{
    int n = strlen(login) - 1;
    int result = 0;
    int tmp;
    int i=0;

    while (n != -1) {
        tmp = 0;
        result += f5_bis(login[i], result, n);
        result &= 0xff;
        i++;
        n--;
    }

    return (result ^ 0xef) & 0x3f;
}

/* fcn.080486d1 */
int f6(char login[])
{
    int result;
    char letter;

    if (login[0] == 0)   /* Yeah... pretty useless indeed */
        return 0;

    result = rand();
    letter = login[0];

    while (--letter) {
        result = rand();
    }

    return ((result & 0xff) ^ 0xe5) & 0x3f;
}
