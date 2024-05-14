#include<iostream>
using namespace std;

int strlen(char a[]) {
    int length=0;
    while (a[length]!=0) length++;
    return length;
}

void strcpy(char a[], char b[]) {
    int i;
    for (i=0; b[i]!=0; i++) a[i]=b[i];
    a[i]=0;
}

void reverse(char a[]) {
    int length = strlen(a);
    for(int i=0; i<length/2; i++) {
        char temp = a[i];
        a[i] = a[length-i-1];
        a[length-i-1] = temp;
    }
}

void delete_char(char a[], char c) {
    int length = strlen(a), j=0;
    char b[length];
    for (int i = 0; i< length; i++) {
        if(a[i]!=c) {
        b[j] = a[i];
        j++;
        }
    }
    b[j]=0;
    strcpy(a,b);
}

void pad_right(char a[], int n) {
    int length = strlen(a);
    if(length<n) {
        for(int i=length; i<n; i++) a[i]=' ';
        a[n]=0;
    }
}

void pad_left(char a[], int n) {
    int length = strlen(a);
    if(length<n) {
        char b[n];
        for(int i=0; i<(n-length); i++)  b[i] = ' ';
        b[n-length] = 0;
        strcat(b,a);
        strcpy(a,b);
    }
}

void truncate(char a[], int n) {
    if(strlen(a)>n) a[n]=0;
}

bool is_palindrome(char a[]) {
    char b[strlen(a)];
    strcpy(b, a);
    reverse(b);
    if(strcmp(a, b)==0) return true;
        else return false;
}

void trim_left(char a[]) {
    int length = strlen(a), i, j=0;
    while(a[j] == ' ') ++j;
    for(i = 0; i < length - j; ++i) a[i] = a[i+j];
    a[i]=0;
}

void trim_right(char a[]) {
    int length = strlen(a), i;
    for(i =length-1; i>=0; --i) {
        if(a[i] != ' ') break;
        else a[i] = 0;
    }
}

int main() {
    char a[] = "Hello world!";
    reverse(a);
    cout<<"Reversed string: "<<a<<endl;

    delete_char(a, 'l');
    cout<<"Deleted 'l' from string: "<<a<<endl;

    pad_right(a, 15);
    cout<<"Padded right string: "<<a<<"."<<endl;

    pad_left(a, 20);
    cout<<"Padded left string: "<<a<<"."<<endl;

    truncate(a, 10);
    cout<<"Truncated string: "<<a<<endl;

    char b[] = "level";
    cout<<(is_palindrome(b) ? "Palindrome" : "Not a palindrome")<<endl;

    char c[] = "  Hello world!  ";
    trim_left(c);
    cout<<"Trimmed left string: "<<c<<endl;

    trim_right(c);
    cout<<"Trimmed right string: "<<c<<endl;

    return 0;
}