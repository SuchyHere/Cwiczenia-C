#include <stdio.h>

int main() {
    for(int i = 1; i < 201; i++){
        if (i % 5 == 0 && i % 7 != 0){
            printf("Foo\n");
        }else if(i % 5 !=0 && i % 7 == 0){
            printf("Bar\n");
        }else if(i % 5 == 0 && i % 7 == 0){
            printf("FooBar\n");
        }else{
            printf("%i\n", i);
        }
    }
    return 0;
}
