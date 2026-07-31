 //Write a C program to find the transpose of a matrix.
 #include <stdio.h>
 void main(){
 int a[10][10],t[10][10];
 int r,c,i,j;
 clrscr();
 printf("Enter total number of rows and columns");
 scanf("%d%d",&r,&c);
 printf("\n enter elements");
 for(i=0;i<r;i++){ 
 for(j=0;j<c;j++){ 
 scanf("%d",&a[i][j]);
 }
}
 for(i=0;i<r;i++){ 
 for(j=0;j<c;j++){ 
 t[j][i]=a[i][j];
 }
}
 printf("*Transpose\n");
 for(i=0;i<c;i++){
 for(j=0;j<r;j++){ 
 printf("%d ",t[i][j]);
 }
 printf("\n");
 }
 getch(); 
}