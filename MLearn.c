//Predicts the price of a house given training data in the form of a matrix (file(n).txt) as argument 1 followed by test data in the form of a matrix
//(file(n).txt) as argument 2. This is the upgraded version of learn.c, saving 600 extra lines of code and 861 lines total.

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>

//Any int is greater than 0

//void printData();
char* AllData;

int row;
int column;
int NXN;
int power=0;
//int MATRIX[0][0];

typedef struct Storage_{
int Row;
int Column;
long double Data;
struct Storage_* Next;
}Storage;

typedef struct Matrix_{

int Row;

int Column;

long double**M;

struct Matrix_* Next;

}Matrix;

void printData();

void readData(FILE* F, Storage** S);

void printMatrixData(Matrix* M);

void AddToStorage(long double data,Storage** Si, int rows, int columns);

void PrintStorage(Storage*Si);

void DeleteStorage(Storage*Si);

void DeleteMatrixes(Matrix* M1);

int Power(int power, int Breaker);

long double** Multiply (Matrix* M1, Matrix* M2);

long double** Transpose(Matrix* M);

//Type 1 for the identity matrix, anything else for normal matrix
long double ** CreateMatrix(int rows, int columns,int type, Matrix** M, Storage* S);

void AppendMatrix(long double** D,int row, int column, Matrix** m);

long double ** CopyMatrix(int rows, int columns, long double**M);

long double** Inverse(Matrix* M1, Matrix* M2);

bool isRREF(long double** M1);

long double** AddRow(long double entry, long double** M1, long int row);

long double** AddRows(long double entry, long double** M1, long int row1, long int row2);

long double** MultiplyRow(long double entry, long double** M1, long int row);

void freeMatrix(long double** M, int column);

long double ** EMATRIX;

long int numOfPow(long double entry);

long double *** MRecord;

long int MCount = 0;

Matrix* BASE = NULL;

//Storage* St=NULL;

int main(int argc ,  char** argv){

FILE* Accessed = fopen(argv[1],"r");
FILE* Accessed2 = fopen(argv[2],"r");

if(Accessed==NULL){
printf("Cannot open file 1");
return 0;
}
if(Accessed2==NULL){
printf("Cannot open file 2");
return 0;
}


else{

Storage* St = NULL;

Storage** S=&St;

Storage* S2 = NULL;
//
readData(Accessed,&St);
//readData(Accessed2,&S2);
//return 0;
//PrintStorage(St);

//printf("ROWS: %d COLUMNS: %d",row,column);

int rows = row;
int columns=column;

//return 0;

//columns++;

CreateMatrix(rows,columns,0,&BASE,St);
//CreateMatrix(rows,columns,0,&BASE,St);
CreateMatrix(columns, columns,1,&BASE,St);


Transpose(BASE->Next);


Multiply(BASE->Next->Next->Next,BASE->Next);


Inverse(BASE->Next->Next->Next->Next,BASE->Next->Next);


Multiply(BASE->Next->Next,BASE->Next->Next->Next);

Multiply(BASE->Next->Next->Next->Next->Next,BASE);

Multiply(BASE->Next,BASE->Next->Next->Next->Next->Next->Next);


//Transpose(BASE);
printf("\n\n\n");
printMatrixData(BASE);
//return 0;


readData(Accessed2,&S2);

rows = row;
columns= column;

columns++;
CreateMatrix(rows,columns,0,&BASE,S2);

//BASE->Next->Next->Next->Next->Next->Next->Row--;

Multiply(BASE->Next->Next->Next->Next->Next->Next->Next->Next->Next,BASE->Next->Next->Next->Next->Next->Next);

printMatrixData(BASE);

DeleteStorage(St);
DeleteStorage(S2);
}


return 0;
}

void readData(FILE* Accessed, Storage** St){
	
long double v;
char g = ' ';
//int row;
int columns;
int c;
row=0;
int rows=0;
columns=0;
c=0;

int MaxCol = 0;
//int MaxRow=0;
int found = 0;
//int found2=0;

char* str =malloc(sizeof(char));
bzero(str,1);
char* app = malloc(2*sizeof(char));
bzero(app,2);

int dCount=0;
int mCount=0;

MaxCol = 0;
int first=0;

bool isNum=false;

while(fscanf(Accessed,"%c",&g)!=EOF){
app[0]=g;
printf("%c",g);
//printf("\n");
if(g=='-'){
mCount++;
continue;
}
if(isdigit(g)||(g=='.'&&isNum==true)){
if(g=='.'){
dCount++;
if(dCount>1){
printf("FORMATTING ERROR");
exit(0);
}
}
strcat(str,app);
isNum=true;
}
else if(isNum==true){
//NEXT
long double val;
sscanf(str,"%LG",&val);
if(mCount%2!=0){
val=val*-1;
}

//printf("VALUE: %LG ROW:%d, COLUMN: %d\n",val,rows,columns);

if(g=='\n'){
if(first==0){
MaxCol=columns;
first=1;
}
if(first!=1||(first==1&&columns<=MaxCol)){
AddToStorage(val,St,rows,columns);
}
//columns=0;
columns=0;
rows++;
printf("\n NEW ROW: %d\n",rows);
printf("\n");
}
else{
if(first!=1||(first==1&&columns<=MaxCol))
AddToStorage(val,St,rows,columns);
}
dCount=0;
mCount=0;
free(str);
str=NULL;
str =malloc(sizeof(char));
bzero(str,1);
bzero(app,2);

if(g!='\n'){
//if(columns<=MaxCol)
columns++;
//else
//columns=0;
}
if(columns>MaxCol&&first==1){

columns=0;
rows++;

printf("\n NEW ROW: %d\n",rows);
printf("\n");


}
isNum=false;
}
}
if(app!=NULL){
free(app);
app=NULL;
}
if(str!=NULL){
free(str);
str=NULL;
}
fclose(Accessed);
MaxCol++;
printf("ROWS: %d COLUMNS:%d",rows,MaxCol);
int h=0;
columns=MaxCol;
//printf("%s",AllData);

printf("STORAGE:\n");
PrintStorage(*St);

printf("ROWS:%d COLUMNS:%d",rows,columns);

row=rows;
column=columns;
return;
}	


void printData(){
int f = 0;
//int SIZE = sizeof(AllData)/sizeof(AllData[0]);
while(AllData[f]!= '\0'){


printf("%c", AllData[f]);

f++;
}	                 
return;

} 

void printMatrixData(Matrix* M){
if(M==NULL){
return;
}
int i = 0;// M->rows;
int k = 0;// M->columns;

printf("\nROWS:%d COLUMNS:%d\n",M->Row, M->Column);
if(M->Next==NULL){
printf("PREDICTED PRICES\n");
}
for(i=0;i<M->Row;i++){
	for(k=0;k<M->Column;k++){
	printf("%LG ",(M->M)[k][i]);
	}
	printf("\n");
}
printf("\n");
printMatrixData(M->Next);
return;

}       

//Return pointer to entire matrix multiplied
long double ** Multiply(Matrix* M1, Matrix* M2){
if(M1==NULL||M2==NULL){
printf("\nNULL MATRICES\n");
return NULL;
}

if(M1->Column!=M2->Row){
printf("\nRow:%d is not the same as Column:%d, CANNOT MULTIPLY\n",M2->Row,M1->Column);
return NULL;
}

long double** NewM = malloc(M2->Column*sizeof(long double*));
//Column by Row Matrix.
int g=0;
while(g<M2->Column){
NewM[g]=malloc(M1->Row*sizeof(long double));
g++;
}

int i=0;
int k=0;
int l=0;
int m=0;
//Columns then rows
long double sum =0;
long double mult = 1;

printf("MATRIX ROWS:%d COLUMNS:%d:\n",M1->Row,M2->Column);
//printMatrixData(NXN,Matrix1);
//printf(" Times MATRIX 2:\n");
//printMatrixData(NXN,Matrix2);
printf("\n");
for (i=0; i<M1->Row; i++){
     m=0;
     for(k=0; k<M2->Column; k++){
	//OR M2->Row
	//m=k;
	//if(m<M1->Column){	
	for(l=0; l<M1->Column; l++){
	//Iterate columns of M1, rows of M2 [col][row]
	//printf(" SECTION [%d,%d]*[%d,%d], %LG * %LG \n",i,l,l,k,(M1->M)[l][i],(M2->M)[k][l]);
	mult = (M1->M)[l][i]*(M2->M)[k][l];	
	//printf("MULTIPLY:%LG BY:%LG = :%LG",(M1->M)[l][i],(M2->M)[k][l],mult);
	sum+=mult;
	}
	printf("\nSUM[%d][%d] :%LG\n",i,k,sum);
	NewM[k][i]=sum;
	sum=0;
	//NEXT COLUM
	}
	
	//}
	//NEXT ROW
}

//printf("\nNEW MATRIX\n\n");
//printMatrixData(NXN,NewM);

//freeMatrix(Matrix1);
//freeMatrix(Matrix2);
/*
for(i=0;i<NXN;i++){
for(k=0;k<NXN;k++){
//Copy NewM to M1
Matrix1[k][i]=NewM[k][i];

}
}

freeMatrix(NewM);

*/



//freeMatrix(Matrix1);

AppendMatrix(NewM,M1->Row,M2->Column,&M2);
//Simpler to just return the new matrix
return NewM;
}

void freeMatrix(long double** Matrix, int column){
if(Matrix==NULL){

return;
}

int i=0;
int j=0;

while(i<column){
free(Matrix[i]);
Matrix[i]=NULL;
i++;
}

free(Matrix);
Matrix=NULL;


return;
}

long double** AddRow(long double entry, long double** M1, long int column){
//long int* TotalRow=M1[row][column];
//Total row space
if(column<0||column>=NXN){
printf("\n INVALID COLUMN #\n");
return M1;
}
long int i=0;
while(i<NXN){
printf("\nROW:%ld:%LG\n",i,M1[i][column]);
M1[i][column]+=entry;
i++;
}

return M1;
}

long double** AddRows(long double entry, long double** M1, long int column1, long int column2){
//long int* TotalRow=M1[row][column];
////Total row space
if(column1<0||column1>=NXN||column2<0||column2>=NXN){
printf("\n INVALID COLUMN #\n");
return M1;
}

long int i=0;
while(i<NXN){
//printf("\nROW:%ld:%LG\n",i,M1[i][column]);
M1[i][column2]=M1[i][column2]+(entry*M1[i][column1]);
i++;
}

return M1;
}

long double** MultiplyRow(long double entry, long double** M1,long int column){
//long int* TotalRow=M1[row][column];
////Total row space
if(column<0||column>=NXN){
printf("\n INVALID COLUMN #\n");
return M1;
}
long int i=0;
while(i<NXN){
printf("\nROW:%ld:%LG\n",i,M1[i][column]);
M1[i][column]*=entry;
i++;
}

return M1;
}


long double** Inverse(Matrix* M1, Matrix* EM){
long int i=0;
long int j=0;
long int k =0;
long double divisor = 0;
NXN=EM->Column;
long double** Matrix = M1->M;
long double** EMatrix = EM->M;
if(!isRREF(EMatrix)||M1->Row!=M1->Column||EM->Row!=EM->Column){
printf("DO NOT HAVE AN IDENTITY MATRIX");
return NULL;
}


for(i=0;i<NXN;i++){
    for(j=0;j<NXN;j++){
    if(i==j){
       if(Matrix[j][i]!=1){
	//Make row such that == 1!
	
	divisor = Matrix[j][i];
	if(divisor!=0){
	MultiplyRow(1.0/divisor,Matrix,i);
        //divisor=EMatrix[j][i];
        MultiplyRow(1.0/divisor,EMatrix,i);
	}
	else{
	printf("\nCANNOT REDUCE\n");
	if(i<NXN)
	i++;
	}
	}
	//PIVOT
	k=0;
	while(k<NXN){
	//Iterate down all rows above and below pivot column
	//Matrix[j][k]... 1 .....
	//NOT PIVOTS
	if(k!=j){   
	if(Matrix[j][k]<0||Matrix[j][k]>0){
        //AddRows(-Matrix[j][k],Matrix,i,k);
        //divisor =  
	AddRows(-Matrix[j][k],EMatrix,i,k);		
	AddRows(-Matrix[j][k],Matrix,i,k);


	}
	else{
	//printf("\nRow:%ld Column:%ld is already 0, %LG \n",j,k,Matrix[j][k]);
	}
	
	if(Matrix[j][j]!=1){
        //Make row such that == 1!
        divisor = Matrix[j][j];
        if(divisor!=0){
	MultiplyRow(1.0/divisor,Matrix,j);
        //divisor=EMatrix[k][k];
	MultiplyRow(1.0/divisor,EMatrix,j);
        }
	else{
	printf("CANNOT REDUCE");
	if(j<NXN)
	j++;
	}
	}
	
        //
	}
	k++;   
	}
	
	
        }
     printf("\n MATRIX NOW:\n");
	printMatrixData(M1);
     
     printf("\n EEEMATRIX NOW:\n");
        printMatrixData(EM);
     //printf("\nMATRIX[%ld][%ld] : %LG\n",j,i,Matrix[j][i]);
     //printf("EMATRIX[%ld][%ld] : %LG",j,i,EMatrix[j][i]);
    }
     printf("\n");
}


//printf("INVERSE!!!");
//printMatrixData(,EMatrix);

//AppendMatrix(EMatrix,j,i,&M1);

return Matrix;
}

bool isRREF(long double** Matrix){
long int i = 0;
long int j = 0;

for(i=0;i<NXN;i++){
    for(j=0;j<NXN;j++){
    if(i==j){ 
	if(Matrix[j][i]==1){

	}
	else{
        printf("\nNot RREF @ %ld,%ld,%LG\n",j,i,Matrix[j][i]);
        return false;
	}   	


    }
    else{
	if(Matrix[j][i]==0||numOfPow(Matrix[j][i])>14){	
	}
	else{
        printf("\nNot RREF @ %ld,%ld,%LG\n",j,i,Matrix[j][i]);
	return false;
	}
	}
    }
}
printf("\nIT Is RREF\n");
return true;
}


long int numOfPow(long double entry){
long int i=0;
if(entry>0&&entry<1){
while(entry<=1){
entry=entry*10;
i++;
}
}
else if(entry>-1&&entry<0){
while(entry>=-1){
entry=entry*10;
i++;
}
}
return i;
}

long double** CreateMatrix(int rows, int columns, int type, Matrix **M1, Storage* S){
// 0 for normal matrix, 1 for  identity matrix
if(rows<1||columns<1){
return NULL;
}

//long double** Y;

long double**M=malloc((columns)*sizeof(long double*));
int i=0;
while(i<columns){
M[i]=malloc(rows*sizeof(long double));
i++;
}

long double** Y=NULL;

int j=0;
if(type==1){
for(i=0;i<columns;i++){
for(j=0;j<rows;j++){
if(j==i){
M[j][i]=1;
}
else{
M[j][i]=0;
}

}
}
}
else{
printf("\nHERE");
Y=malloc(sizeof(long double*));
Y[0] =malloc(rows*sizeof(long double));
Storage** Su=&S;
while(*Su!=NULL){
printf("Row:%d Column:%d Data: %LG ADDED\n",(*Su)->Row,(*Su)->Column,(*Su)->Data);
//printf("\n\n\n");
if((*Su)->Column<columns-1){
M[(*Su)->Column+1][(*Su)->Row]=(*Su)->Data;
}

if((*Su)->Column==0){
M[(*Su)->Column][(*Su)->Row]=1.0;
}

if((*Su)->Column==columns-1){
Y[0][(*Su)->Row]=(*Su)->Data;
}

Su=&((*Su)->Next);
}
}

/*
Matrix* M2=M1;
Matrix* M3;
while(M2!=NULL){
M3=M2->Next;
}
*M1=malloc(sizeof(Matrix));
(*M1)->Row=rows;
(*M1)->Column=columns;
(*M1)->Next=NULL;
(*M1)->M=M;
*/

if(Y!=NULL){
AppendMatrix(Y,rows,1,M1);
}

if(*M1==NULL){
 *M1=malloc(sizeof(Matrix));
(*M1)->Row=rows;
(*M1)->Column=columns;
(*M1)->Next=NULL;
(*M1)->M=M;
}
else{
AppendMatrix(M,rows,columns,M1);
}
return M;
}

long double** CopyMatrix(int rows, int columns, long double** Matrix){

if(rows<1||columns<1){
return NULL;
}

long double**M=malloc(columns*sizeof(long double*));
int i=0;
while(i<rows){
M[i]=malloc(columns*sizeof(long double));
i++;
}
int j=0;

for(i=0;i<columns;i++){
for(j=0;j<rows;j++){
M[j][i]=Matrix[j][i];
}

}




return M;
}

void AddToStorage(long double data, Storage** S,int rows, int columns){

if(*S==NULL){
//printf("\nADDING: %LG\n",data);
*S=malloc(sizeof(Storage));
(*S)->Next=NULL;
(*S)->Data=data;
(*S)->Row=rows;
(*S)->Column=columns;
PrintStorage(*S);
return;
}

AddToStorage(data,&((*S)->Next),rows,columns);

return;
}

void DeleteStorage(Storage*S){
Storage* G = NULL;
while(S!=NULL){
G=S->Next;
free(S);
S=NULL;
S=G;
printf("FREE");
}
return;
}

void PrintStorage(Storage* S){
if(S!=NULL){
printf("Row:%d Column:%d Data:%LG",S->Row,S->Column,S->Data);
printf("\n");
PrintStorage(S->Next);
}
//printf("NULL");
return;
}

void DeleteMatrixes(Matrix* M){
if(M==NULL){
printf("\nFREED ALL\n");
return;
}
Matrix* M2=(M)->Next;
int i=0;
int j=(M)->Column;

for(i=0;i<j;i++){
if(i!=0){
free(((M)->M)[i]);
((M)->M)[i]=NULL;
}
}

free(((M)->M));
(M)->M=NULL;
free((M));
(M)=NULL;
DeleteMatrixes(M2);
return;
}

long double** Transpose(Matrix* M){
if(M==NULL){
return NULL;
}
long double** M1 = malloc((M->Row)*sizeof(long double*));
int i=0;
while(i<M->Row){
M1[i]=malloc((M->Column)*sizeof(long double));
i++;
}

int j=0;
for(i=0;i<M->Column;i++){
for(j=0;j<M->Row;j++){
M1[j][i]=(M->M)[i][j];
}
}

AppendMatrix(M1,i,j,&M);
return M->M;
}

void AppendMatrix(long double** D, int row, int column, Matrix** M){
if(M==NULL){
printf("\nNULL POINTER\n");
return;
}
if(*M==NULL){
(*M)=malloc(sizeof(Matrix));
(*M)->Row=row;
(*M)->Column=column;
(*M)->Next=NULL;
(*M)->M=D;
return;
}
AppendMatrix(D,row,column,&((*M)->Next));
return;
}
