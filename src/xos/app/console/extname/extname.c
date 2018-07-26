/*/
///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: extname.c
///
/// Author: $author$
///   Date: 7/23/2018
///////////////////////////////////////////////////////////////////////
/*/
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv, char** env) {
    int err = 0;
    const char* arg = 0;
    if ((1 <= argc) && (argv) && (arg = argv[1]) && (arg[0])) {
        if ((arg = strrchr(arg, '.')) && (arg[0])) {
            printf("%s\n", arg+1);
        }
    } else {
        const char* exename = "extname";
        if ((0 < argc) && (argv) && (arg = argv[0]) && (arg[0])) {
            exename = arg;
            if ((arg = strrchr(arg, '/')) && (arg[0])) {
                exename = arg+1;
            }
        }
        printf("usage %s path\n", exename);
    }
    return err;
}