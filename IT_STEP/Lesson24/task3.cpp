#include"book.h"

using namespace std;

int main(){
    class Book book("NAN");
    book.set_title("Hello!");
    book.print_title();
}