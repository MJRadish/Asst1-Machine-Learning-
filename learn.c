//Machine Learning Algorithm which predicts the prices of a house given its components. Takes two arguments, argument 1 is the training data.
//Argument 2 is the testing data. Program outputs the predicted prices of each house given the components after calculating the weights of each component.
//On assignment 0, there is an inverse calculator which is more efficient than this current one. Upgrade has been made to this version in MLearn.c, MLearn is the executable file.
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

char* readData(int file);
char* AllData;

double** Matrix;

double** IDMatrix;

double** IDTemp;

double** Matrix2;

double** TransposeMatrix;

double** InverseMatrix;

double** OneMatrix;

double** TMatrix;

double** OrigMatrix;

int columns;

int rows;

int rows2;

int columns2;

void printMatrix(int type, double** M);

void AddRow(double** N,int type, int row, int column,int rowTwo, double data);

void addData(int value, int row, int column);

void MultiplyRow(double** N, double Mag, int row, int column);

void MultiplyMatrix(double** M, double** N);

void  MULT(int type,double**M, double**N);

void Inverse(double**M, double**T);

void DivideItNow(double** N);

int NumofZeroes(double **TestMatrix, int row, int column);

double Magnitude;

void UpdateMagnitude(double **TestMatrix);

int IsEchelon(double** Matrix);

int hasZeroes(int type, double** M,int row);

int main (int argc, char* argv[]){
Magnitude=0;

//FILE* accessed = fopen(argv[1],"r");
////////////////////////////////////////////////FIRST FILE OPEN
int accessed = open(argv[1],O_RDONLY);

int accessed2 = open(argv[2],O_RDONLY);

columns =0;
rows = 0;
if(accessed == -1||accessed==0||accessed2==-1||accessed2==0){
printf("0");
return 0;
}

//printf("Made it");
//readData(accessed);

//printf("Made it");

close(accessed);
FILE * enter = fopen(argv[1],"r");

//First get the two characters
//
char* reader = malloc(100*sizeof(char));
int y=0;
while(y<100){
reader[y]= '\0';
y++;
}
int times =0;
y=0;
//int addit;
char casey;
int Length =0;


while(fscanf(enter, "%c", &casey)!=EOF&&times<2){
Length++;
if(casey!='\n'&&casey!='\t'){
reader[y]=casey;
}
else{
times++;
if(times==1){
columns = atoi(reader);
y=0;
while(y<100){
reader[y]= '\0';
y++;
}
y=0;
continue;
}
else{
rows=atoi(reader);
y=0;
while(y<100){
reader[y]= '\0';
y++;
}
y=0;
//continue;
break;
}
}


y++;
//times++;
}

//printf("Columns: %d, Rows: %d, Length: %d", columns, rows, Length);

columns = columns+1;

y=0;
while(y<100){
reader[y]= '\0';
y++;
}

//Now Read the rest of the file
double data;
///double divisions = 1;
//int Dint;
//double precision=.1;
//printf("\n");
//y=0;

char* readDot = malloc(100*sizeof(char));
y=0;
while(y<100){
readDot[y]= '\0';
y++;
}
y=0;

int i=0;

//columns--;
//int k=0;
////////////////////////////////////////////////////////////////  
//double** TryMatrix = malloc(sizeof(double*));
	//TryMatrix = malloc(columns*sizeof(double));
//OneMatrix = malloc(rows*sizeof(double*));
//OneMatrix[0]=malloc(rows*sizeof(double));

//columns++;


Matrix = malloc((columns+1)*sizeof(double*));
InverseMatrix=malloc((rows)*sizeof(double*));
int g=0;
while(g<columns){
Matrix[g]=malloc(rows*sizeof(double));
//OneMatrix[g]=malloc(rows*sizeof(double));
//InverseMatrix[g]=malloc(columns*sizeof(double));
//TryMatrix[g]=malloc(sizeof(double));
g++;
}
g=0;

while(g<rows){
InverseMatrix[g]=malloc((columns+1)*sizeof(double));
//OneMatrix[g]=malloc((columns+1)*sizeof(double));
g++;
}


g=0;
/*
while(g<rows){
//OneMatrix[0][g]=1;
Matrix[0][g]=1;
InverseMatrix[g][0]=1;
//printf("DATA : %lf", OneMatrix[0][g]);
g++;
}

*/

        //                                
//columns=columns+1;

///////////////////////////////////////////////////////////////FIXED!!!!!!!!!!!!
//*Matrix = malloc(rowssizeof(int));

//printf("THE INVERSE MAT\n");
//printMatrix(0, InverseMatrix);

i=0;

int j=0;
//i=0;

//printf("MMMMMM");

//int iterate =0;

//return 0;

OrigMatrix = malloc(sizeof(double*));

i=0;

OrigMatrix[0]=malloc(rows*sizeof(double));

/*
while(i<rows){
OrigMatrix[i]=malloc(sizeof(double));
i++;
}

*/
i=0;
j=1;


//int vv =0;

int gogo=0;

int nogo=1;

//THE NEXT ONE COLUMN

while(fscanf(enter,"%lf%c",&data,&casey)!=EOF){

if(j<columns&&i<rows&&nogo!=0){
//printf("Bounds: %d,%d\n", i,j);
//printf("DATA: %lf", data);

Matrix[j][i]=data;

//if(i<columns)
//if(i!=1){
InverseMatrix[i][j]=data;
}
else{

//printf("\nGOGO: %lf of row: %d\n", data,gogo);

OrigMatrix[0][gogo]=data;

//printf("\nGOGOdodo: %lf\n", OrigMatrix[0][gogo]);

if(gogo<rows){
gogo=gogo+1;
}
else{
break;
}
nogo=1;
continue;

}
j++;
if(j>=columns){
j=1;
nogo=0;
if(i<=rows){
i++;
}
else{
//printf("END");
break;
}
continue;

}
}






i=0;
j=0;
g=0;
while(g<rows){
Matrix[0][g]=1;
InverseMatrix[g][0]=1;
g++;
}

OneMatrix=malloc(sizeof(double*));
i=0;

OneMatrix[i]=malloc(rows*sizeof(double));

i=0;
//return 0;


/////////////////////////////////////////////////////////VALUES VECTOR
//printf("\nVALUE VECTOR\n");
while(i<rows){
//printf("%lf\n",Matrix[columns-1][i]);
OneMatrix[0][i]=Matrix[columns-1][i];
i++;
}
/////////////////////////////////////////////////////////VALUES VECTOR

/////////////////////////////////////////////////////////
//STORE ORIGINAL MATRIX
double** O = malloc((columns)*sizeof(double*));

i=0;

while(i<columns){
O[i]=malloc(rows*sizeof(double));

i++;
}


for(i=0;i<rows;i++){
	for(j=0;j<columns;j++){
	O[j][i]=Matrix[j][i];
}

}

//printf("\nORIG MATRIX:\n");


printMatrix(1,O);

//return 0;

/////////////////////////////////////////////////////////
//STORE ORIGINAL MATRIX
//
//
//





/////////////////////////////////////////////////////////
//TRANSPOSE * VECTOR
MULT(3,OneMatrix,InverseMatrix);

//printf("\nTranspose * One MAtrix\n");

//printf("\n");
for(i=0;i<rows;i++){
	for(j=0;j<columns;j++){
	//printf("%lf\n",TMatrix[i][j]);
	}	
	//printf("\n");
	break;
}
/////////////////////////////////////////////////////////
//TRANSPOSE * VECTOR



/////////////////////////////////////////////////////////
//MATRIX * TRANSPOSE
int u=0; while(u<columns+1){
OneMatrix[0][u]=TMatrix[0][u];
u++;
}


MULT(0,Matrix,InverseMatrix);

//printf("\nMATRIX * Transpoze:\n");

printMatrix(-1,TMatrix);
 
for(i=0;i<columns;i++){
	for(j=0;j<columns;j++){
	Matrix[i][j]=TMatrix[i][j];
	}
}
/////////////////////////////////////////////////////////
//MATRIX * TRANSPOSE



/////////////////////////////////////////////////////////
//CREATE ID
IDTemp = malloc((columns)*sizeof(double*));
int m=0;
int v=0;
while(v<columns){
IDTemp[v]=malloc((columns)*sizeof(double));
v++;
}


/////////////////////////////////////////////////////////
// CREATE ID
for(v=0;v<columns;v++){
        for(m=0;m<columns;m++){
        if(m==v){
        //IDMatrix[m][v]=1;
        IDTemp[m][v]=1;
        }
        else{
        IDTemp[m][v]=0;
        }
        }
}
/////////////////////////////////////////////////////////
//CREAT ID

/////////////////////////////////////////////////////////
//CALCULATE THE INVERSE1!!!!!!!11
     
//printf("\n WHOLE MATRIX:\n");
Inverse(Matrix,IDMatrix);
/////////////////////////////////////////////////////////
//CACULATE THE INVERSE!!!


/////////////////////////////////////////////////////////
//MULTIPLY TRANSPOSE BY THE!!!!! INVERSE MATRIX
//printf("\nEchelonMatrix:\n");
printMatrix(-1,Matrix);

MULT(-7,InverseMatrix,IDTemp);
/////////////////////////////////////////////////////////
//MULTIPLY TRANSPOSE BY INVERSE MATRIX


double ** InverseTransp = malloc(rows*sizeof(double*));

i=0;

while(i<rows){
InverseTransp[i]=malloc(columns*sizeof(double));
i++;
}

int k=0;
for(i=0;i<columns;i++){
	for(k=0;k<rows;k++){
	InverseTransp[k][i]=TMatrix[k][i];
	}
}

/////////////////////////////////////////////////////////
//TPOSE
//printf("\n Transpose Matrix:\n");
printMatrix(0,InverseMatrix);
/////////////////////////////////////////////////////////
//TPOSE


/////////////////////////////////////////////////////////
//INVERSE * TRANSPOSE
//printf("\nINVERSE TRADDDDDDDDDDDDDDDDDDDDDtransp\n");

printMatrix(0,InverseTransp);
/////////////////////////////////////////////////////////
//INVERSE * TPOSE

MULT(4,OneMatrix,IDTemp);

/////////////////////////////////////////////////////////
// INVERSE * TRANSPOSE *   VECTOR 

//printf("\n INVERSE * TRANSPOSE*VECTOR");

for(i=0;i<rows;i++){
	OneMatrix[0][i]=OrigMatrix[0][i];
}

int d=0;

MULT(-9,OneMatrix,InverseTransp);

d=0;
while(d<rows){
OneMatrix[0][d]=TMatrix[0][d];
//printf("%lf\n",TMatrix[0][d]);
d++;
}
/////////////////////////////////////////////////////////
//INVERSE*TRANSPOSE *     VECTOR




/////////////////////////////////////////////////////////
//W * X TEST
//printf("\nO:\n");

printMatrix(1,O);

//printf("\nW*X TESTTT\n");

MULT(-10,OneMatrix,O);

i=0;

while(i<rows){
//printf("%lf\n",TMatrix[0][i]);
if(TMatrix[0][i]==0){
break;
}
i++;
}
/////////////////////////////////////////////////////////
//W*X TESTTTTTTTTTTTTT


//return 0;


FILE* enter2 = fopen(argv[2],"r");

reader = malloc(100*sizeof(char));
y=0;
while(y<100){
reader[y]= '\0';
y++;
}
times =0;
y=0;
//int addit;
//char casey;
//int Length =0;
//
//

//printf("\n THE SECOND FILLE");

while(fscanf(enter2,"%c",&casey)!=EOF){
if(casey=='\n'){
break;
}
reader[y]=casey;
y++;
//printf("%c",casey);

}

//printf("columns: %d", columns);



//printf("\nEND OF SCAN\n");
rows2=atoi(reader);

//Now Read the rest of the file
//double data;
//double divisions = 1;
//int Dint;
//double precision=.1;
//printf("\n");
//y=0;
//char* readDot = malloc(100*sizeof(char));
y=0;
while(y<100){
readDot[y]= '\0';
y++;
}
y=0;
//

j=0;
i=0;

columns2=columns+1;

//printf("columns: %d", columns);

//printf("The rows:, the same columns:  Old columns: %d %d %d \n", rows2, columns2,columns);


int f=0;
Matrix2 = malloc((columns2)*sizeof(double*));

//columns2++;

while(f<columns2){
Matrix2[f]=malloc(rows2*sizeof(double));
f++;
}
f=0;

while(f<rows2){
Matrix2[0][f]=1;
f++;
}
f=0;

columns2--;

while(fscanf(enter2,"%lf%c",&data,&casey)!=EOF){

if(j<columns2&&i<rows2){
//printf("%lf%c",data,casey);
//printf("\nBounds: %d,%d\n", j+1,i);

Matrix2[j+1][i]=(double)data;
j++;

if(j>=columns2-1){
j=0;
if(i<rows2){
i++;

}

else{

break;
}
	}
		}


	}


/*
printf("\nMATRIX 2!\n");
for(j=0;j<rows2;j++){
	for(i=0;i<columns2;i++){
	printf("%lf ",Matrix2[i][j]);
	}
	printf("\n");
}
*/


MULT(-5,OneMatrix,Matrix2);

//printf("FINAL MATRIX\n");

//printMatrix(-5,TMatrix);

f=0;

while(f<rows2){
	printf("%0.0f\n", TMatrix[0][f]);

f++;
}




//printf("END");


close(accessed);
fclose(enter);
free(Matrix);
//free(OneMatrix);

/*
free(TMatrix);
free(InverseMatrix);
free(OrigMatrix);
free(IDTemp);
free(IDMatrix);
free(TransposeMatrix);
*/
return 0;
}

void AddRow(double** N,int type,int row,int column,int rowTwo,double Data){
//Set AllData to temp then set temp to all Data after
//
int i=0;
int k=0;
if(type>0){
for(i=row; i<row+1; i++){
	for(k=0; k<columns; k++){
	//////
	N[k][i]+=N[k][rowTwo];
	}
	break;
}
}
else if(type==0){
for(i=row; i<row+1; i++){
        for(k=0; k<columns; k++){
        //////
    	N[k][i]+=Data;
                        }
	break;

                        }
        

}

else{ // Scalar
int g=0;
for(i=rowTwo;i<rowTwo+1;i++){
for(k=0; k<columns; k++){
	//
	//
	//printf("ROw 1: %lf\n, Row2: %lf\n",N[i][k],N[column][g]);
	//printf("DATA : \n%lf, columns: %d\n DATA TIMES ROW: %lf",N[k][i],columns, Data*N[k][rowTwo]);
	
  	N[i][k]=N[i][k]+Data*N[column][g];
        g++;                
	}
		break;
                        }
     

//printf("ENDDD\n");
}
////////////////////////////////////////////Will Alter N, B is the row that is

return;
}

void MULT(int type, double**M, double**N){
int i=0;
int j=0;
double product =1.000000;
double sum=0.000000;
int ji=0;

//double*ptr = malloc(sizeof(double));


//printf("INSIDE");

if(type<2){
TMatrix=malloc(columns*sizeof(double*));


while(ji<columns){
TMatrix[ji]=malloc(columns*sizeof(double));
ji++;
}
}
ji=0;
//int ij=0;
int go=0;
//if(type==0){
if(type==0){
for(i=0;i<columns;i++){
	//ij=i;
	go=0;
	while(go<columns){
	for(j=0;j<rows;j++){
	product=M[i][j]*N[j][go];
	//printf("\nMultiply %lf by %lf", M[i][j], N[j][go]);
	//printf("\n COL>>>> %d, ROW???? %d",i,j);
	sum+=product;
	//TMatrix[i][go]=sum;
	}
	TMatrix[i][go]=sum;
	//printf("\nTotal product: %lf\n", sum);
	sum=0;
	go++;
	}
	//printf("\n");

}
}
else if(type==-8){
//int gf =0;
//
for(i=0;i<1;i++){
        //ij=i;
                go=0;
                        while(go<columns){
                                for(j=0;j<rows;j++){////////////////////HEREEEEEEE
                                        product=M[i][j]*N[j][go];
                                  //             printf("\nMultiply %lf by %lf", M[i][j], N[j][go]);
                                                       // printf("\n COL>>>> %d, ROW???? %d",i,j);
                                                                sum+=product;
									//gf++;
                                                                        //TMatrix[i][go]=sum;
                                                                                }
											//gf=0;		
                                                                                        TMatrix[i][go]=sum;
                                    //                                                            printf("\nTotal product: %lf\n", sum);
                                                                                                        sum=0;
                                                                                                               go++;
                                                                                                                       }
        //                                                                                                                        printf("\n");
        
                                                                                                                                }
        










}
else if( type==-9){
//int gotten =0;
for(i=0;i<1;i++){
        //ij=i;
                        go=0;
                                                while(go<columns){
						
                                                                                for(j=0;j<rows;j++){////////////////////HEREEEEEEE
                                                                                                                        product=M[i][j]*N[j][go];
                                //                                                                                                                                     printf("\nMultiply %lf by %lf", M[i][j], N[j][go]);
                                                                                                                                                                                                                              // printf("\n COL>>>> %d, ROW???? %d",i,j);
                                                                                                                                                                                                                                                                                              sum+=product;
                                                                                                                                                                                                                                                                                                                                                                      //gf++;
                                                                                                                                                                                                                                                                                                                                                                                                                                              //TMatrix[i][go]=sum;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      //gf=0;    
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              TMatrix[i][go]=sum;
                              //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                printf("\nTotal product: %lf\n", sum);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    sum=0;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     go++;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    //                                                                                                                        printf("\n");
        
        
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 }
        
        
        
        
        
        
        
        
        
        
        
        




}
else if(type==-7){

TMatrix = malloc(rows*sizeof(double*));
int r=0;

while(r<rows){
TMatrix[r]=malloc(columns*sizeof(double));
r++;
}

r=0;

for(i=0;i<columns;i++){
        //ij=i;
                go=0;
		r=0;
                        while(go<rows){
                                for(j=0;j<columns;j++){
                                        product=N[i][j]*M[go][j];
                          //                      printf("\nMultiply %lf by %lf", N[i][j], M[go][j]);
                                                       // printf("\n COL>>>> %d, ROW???? %d",i,j);
                                                                sum+=product;
                                                                        TMatrix[go][i]=sum;
                                                                                }
                                                                                       //TMatrix[i][go]=sum;
                            //                                                                   printf("\nTotal product: %lf\n", sum);
                                                                                                        sum=0;
														go++;
                                                                                                                
														r++;
                                                                                                                        }
           //                                                                                                                     printf("\n");
        
                                                                                                                                }
        

//printf("MADE IT");

}
else if(type==1){
for(i=0;i<columns+1;i++){
        //ij=i;
                go=0;
        while(go<columns+1){
        for(j=0;j<columns+1;j++){
        product=M[i][j]*N[j][go];
        //printf("\nMultiply %lf by %lf", M[i][j], N[j][go]);
        sum+=product;
        //TMatrix[go][i]=sum;
        }
	TMatrix[go][i]=sum;
        //printf("\nTotal product: %lf\n", sum);
        sum=0;
        go++;
        }
       // printf("\n");
        }
        
}
else if(type==3){
//free(TMatrix);
//printf("MAde it");


TMatrix=malloc(sizeof(double*));

int h=0;

TMatrix[h]=malloc(rows*sizeof(double));

/*
while(h<rows){
TMatrix[h]=malloc(sizeof(double));
h++;
}
*/

//printf("MADE EASG");
for(i=0;i<1;i++){
        //ij=i;
        go=0;
       	while(go<columns){
        for(j=0;j<rows;j++){
	product=M[i][j]*N[j][go];
       //	printf("\nMultiply %lf by %lf", M[i][j], N[j][go]);
        
	sum+=product;
        
        }
        TMatrix[i][go]=sum;         
//	printf("\nTotal product: %lf\n", sum);
        sum=0;
        go++;
        }
       // printf("\n");
        break;
	}
        






}
else if(type==-5){
TMatrix=malloc(sizeof(double*));

int h=0;

TMatrix[h]=malloc(rows2*sizeof(double));

/*
 * while(h<rows){
 * TMatrix[h]=malloc(sizeof(double));
 * h++;
 * }
 * */



//printf("MADE EASFFFFFFfG");
for(i=0;i<1;i++){
        //ij=i;
                go=0;
                        while(go<rows2){
                                for(j=1;j<columns2;j++){
					//if(M[i][j]!=0)
                                        product=(M[i][j])*N[j][go];
					///else
					//product=0;
  			//		  printf("\nMultiply %lf by %lf", M[i][j], N[j][go]);
        
                                                        sum+=product;
        
                                                                }
									//sum=sum+M[0][0];
                                                                        TMatrix[i][go]=sum;
                                				TMatrix[i][go]+=M[0][0];                                              
			//	printf("\nTotal product + sum: %lf %lf\n", sum, M[0][0]);
                                                                                        sum=0;
                                                                                                go++;
                                                                                                        }
                               //                                                                                 printf("\n");
                                                                                                                        break;
                                                                                                                                }
        
                                                                                                                                




}
else if(type==-10){
double sum2 = 0.000000;
TMatrix=malloc(rows*sizeof(double*));

int a=0;

while(a<rows){
TMatrix[a]=malloc(sizeof(double));
a++;
}

//printf("MADE EASG");
for(i=0;i<1;i++){
        //ij=i;
                go=0;
                        while(go<rows){
                                for(j=1;j<columns;j++){
                                        product=(double)M[i][j]*(double)N[j][go];
                                       
                   //printf("\nMultiply %lf by %lf =? %lf\n", M[i][j], N[j][go],product);                                                        TMatrix[i][go]+=product;
                                                                sum2=(double)sum2+(double)product;
                                                                        //printf("sum: %lf",sum2);
                                                                                }
                                                                                        TMatrix[i][go]=sum2+M[0][0];
                                                 ///////////////////////////                                               printf("\nTotal product: %lf\n", sum2+M[0][0]);
                                                                                                        sum2=0;
                                                                                                                go++;
                                                                                                                        }
                                                                                                                               // printf("\n");
                                                                                                                                       break;
                                                                                                                                               }                                                                                                                                              



}
else{

double sum2 = 0.000000;
TMatrix=malloc(rows*sizeof(double*));

int h=0;

while(h<rows){
TMatrix[h]=malloc(sizeof(double));
h++;
}

//printf("MADE EASG");
for(i=0;i<1;i++){
        //ij=i;
        go=0;
        while(go<rows){
        for(j=0;j<columns;j++){
        product=(double)M[i][j]*(double)N[j][go];
      ///////////////////////////////////////////  printf("\nMultiply %lf by %lf =? %lf\n", M[i][j], N[j][go],product);
	//TMatrix[i][go]+=product;
	sum2=(double)sum2+(double)product;
	//printf("sum: %lf",sum2);
        }
        TMatrix[i][go]=sum2;
   ////////////////////////////////     printf("\nTotal product: %lf\n", sum2);
        sum2=0;
        go++;
        }
       // printf("\n");
        break;
        }
}


return;
}

void MultiplyRow(double** N,double Mag,int row,int rowTwo){
int i=0;
int k=0;
for(i=row; i<row+1; i++){
	for(k=0; k<columns; k++){
	
	//else{
	N[i][k]=N[i][k]*Mag;
	
	/*if(N[k][i]>=.98000000&&N[k][i]<=1.00000000){
	N[k][i]=1.00000;
	}*/
//	}
	}
	break;
}
return;
}


void addData(value, row, column){
Matrix[column][row]=value;
return;
}
char* readData(int file){
int determinant = 0;
char* piece = (char*)malloc(100*sizeof(char));
char*ptr;

if(piece==NULL){
return NULL;
}

int go = 0;
while(go<100){
piece[go]='\0';
go++;
}

int Checkit = 1;

do{
Checkit =read(file,piece,99*sizeof(char));

if(Checkit==-1){
return NULL;
}
if(determinant ==0){
AllData=(char*)malloc(100*sizeof(char));
}
else{
ptr = realloc(AllData,100*sizeof(char));
if(ptr==NULL){
return NULL;
}
}

int startp = 0;
int t =determinant;

while(piece[startp]!='\0'){
AllData[t]=piece[startp];
t++;
startp++;
}
AllData[t]='\0';
determinant = determinant + Checkit;

Checkit = read(file,piece,99*sizeof(char));
}while(Checkit!=0);


return AllData;
}




void printMatrix(int type, double ** M){
int i=0;
int k=0;
double* ptr = malloc(sizeof(double));

if(type==1){
for(i=0; i<rows; i++){
	for(k=0; k<columns; k++){
//////////////////////	printf("%lf ", M[k][i]);
	}
//////////	printf("\n");
}
}
else if(type==0){
for(i=0; i<columns; i++){
        for(k=0; k<rows; k++){
        //////////////////////printf("%lf ", M[k][i]);
        }
    ///////////////////    printf("\n");
}
}

else if(type==-1){

//double**ptr = malloc(sizeof(double*));

for(i=0; i<columns; i++){
        for(k=0; k<columns; k++){
	//*ptr = &M[i][k];
/*	if(ptr==0){
	return;
	}*/
        /*if(M[i][k]==0){
	return;
	}*/
	/////////////printf("%lf ", M[i][k]);
        }
        ///////////////printf("\n");
}
}
else if(type==2){
for(i=0; i<1; i++){
        for(k=0; k<rows; k++){
       /* if(M[i][k]==0){
	printf("END");
	return;
	}*/
	//else{
	//////////////////printf("%lf\n", M[i][k]);
	//}
        }
        //////////////////////printf("\n");
}
}
else if(type==-2){
for(i=0; i<columns; i++){
        for(k=0; k<columns; k++){
        //*ptr = &M[i][k];
        /*      if(ptr==0){
                return;
                        }*/
                                /*if(M[i][k]==0){
                                        return;
                                                }*/
                                                      // //////////////////// printf("%lf ", M[i][k]);
                                                                }
                                                        //               /////////////////// printf("\n");
                                                                        }
                                                                        


}
else if(type==-3){
//ptr = M;

ptr = &M[0][0];
for(i=0; i<1; i++){
        for(k=0; k<columns; k++){
	if(ptr==0){
	return;
	}
        //*ptr = &M[i][k];
                /*      if(ptr==0){
                                return;
                                                        }*/
                                                                                        /*if(M[i][k]==0){
                                                                                                                                return;
                                                                                                                                                                                }*/
                                   //             ////////////////////////// printf("%lf\n", M[i][k]);
                                                      ptr = &M[i][k+1];
					                                                                                                                                                                                                                                                  }
                                                                       //   ////////////////////////////////////                                                                                                                                                                                                                                                                                                      printf("\n");
                                                                                                                                                                                                                                                                                                                                                                                                                                                        }
        
        
        
        



}
else if(type==-4){
for(i=0; i<1; i++){
        for(k=0; k<rows; k++){
           /*if(M[i][k]==0){
                                                                                                                                return;
                                                                                                                                                                                }*/
                              ///////////////////////////////////////////////////// //printf("%lf\n", M[i][k]);
                                                                                                                                                                                                                                                                                                        }
                                 //                        printf("END LOOP\n");
                                                                                                                                                                                                                                                                                                                                                                                                                                                        }
        
        
        
        




}
else if(type==-5){
for(i=0; i<1; i++){
        for(k=0; k<rows2; k++){
        
                                                                                   //////////////////////                  //                                                                                                                                                                                                                                                                                                                                                                                                                                                  printf("%lf\n", M[i][k]);
        
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          }
                                                                                                   //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                printf("END LOOP\n");
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           }
        
        
        
        
        
        
        
        
        









}

return;
}


void UpdateMagnitude(double** TestMatrix){
int i=0;
int k=0;

for(i=0;i<rows;i++){
	for(k=0;k<columns;k++){
	if(TestMatrix[k][i]>0){
	Magnitude+=TestMatrix[k][i];
	}		
	else{
	Magnitude+= -1*TestMatrix[k][i];
	}
	}
}
return;
}

int NumofZeroes(double** TMatrix,int row, int column){
int i=0;
int k=0;
int count=0;

for(i=row; i<row+1; i++){
	for(k=column; k<columns; k++){
	if(TMatrix[k][i]==0){
	count++;
	}
	}
}



return count;
}

int IsEchelon(double** M){
int i=0;
int k=0;

int g=0;
int r=0;

for(i=0; i<rows; i++){
	for(k=0; k<columns; k++){
	printf("%lf\n",M[k][i]);
	if(M[k][i]>=(double)1&&i==k){
	printf("MADE TO");
	if(M[k][i]>1){
	printf("Data failed: %lf", M[k][i]);
	
	return 0;
	
	}
		for(g=i-1;g>-1;g--){
		printf("Inside1: %lf\n", M[k][g]);
		if(M[k][g]==(double)0){
		printf("Data succeeded: %lf\n", M[k][g]);
		}
		else{
		printf("Data failed: %lf\n", M[k][g]);
		return 0;
		}
		}
		
		for(r=k-1;r>-1;r--){
		
		printf("Inside: %lf\n", M[r][i]);
		if(M[r][i]==(double)0){
		//Good to go
		printf("Data succeeded: %lf\n", M[r][i]);
		}
		else{
	printf("Data failed: %lf\n", M[r][i]);
		return 0;
			}
			}
		}
	
	}
}
return 1;
}

void Inverse(double** M, double**T){
int i=0;
int j=0;
double getOne=0;
//M is the oritinal matrix
for(j=0;j<rows;j++){
	for(i=0;i<columns;i++){
	if(i==j){
		}else if(M[i][i]==1){break;}
		else if(M[i][i]>1){
		getOne=M[i][i];
		MultiplyRow(IDTemp,(1/getOne),i,i);
		MultiplyRow(M,(1/getOne),i,i);
		}/////////////////////////////////////////////////
		else if(M[i][i]<1){
		getOne=M[i][i];
		MultiplyRow(IDTemp,(-1/getOne),i,i);
		MultiplyRow(M,(-1/getOne),i,i);
		}
	}
}
	

DivideItNow(M);

return;
}

void DivideItNow(double** N){
//Divides rows and then goes to the next non diagonol row, also check if the subtraction will make the one a zero, then it will just add one to the row to sub
//subtract from and then subtract like normal....
int i=0;
int k=0;
double getOne =0;
//For left lower half         
int d=0;
int f=0;
//printf("Now just do it simply!!");
for(k=0; k<columns; k++){
	f=k;
        for(i=0;i<columns;i++){
		if(i==k){
		
		getOne=1/N[k][k];
		MultiplyRow(N,getOne,k,k);
		MultiplyRow(IDTemp,getOne,k,k);
                
		d=i;
 		
	//	   printf("\n");

         //       printMatrix(-1,N);
          //      printf("\n");               


		while(d<columns){
             	
		if(d!=k){                    //                                            printf("CC%lf\n",N[d][i]);
                 getOne = N[d][i];                                                                                 //printf("getone: %lf",getOne);
                 AddRow(N,-1,i,f,d,-getOne);
		 AddRow(IDTemp,-1,i,f,d,-getOne);
		
		getOne=1/N[k][k];
                MultiplyRow(N,getOne,k,k);
                MultiplyRow(IDTemp,getOne,k,k);                


		//printf("\n");

		//printMatrix(-1,N);
	//	printf("\n");

		}
                d++;

		}
		}
		}
}               

f=0;

for(k=0; k<columns; k++){
	f=k;
	for(i=0;i<columns;i++){
		if(i==k){
		d=i;
		while(d>=0){
		if(d!=k){
		getOne = N[d][i];
		AddRow(N,-1,i,f,d,-getOne);
		AddRow(IDTemp,-1,i,f,d,-getOne);
	///	printf("\n");
//        printMatrix(-1,N);
   //     printf("\n");

		}
		d--;
		}
	//	printf("\n");
	  //      printMatrix(-1,N);
        //	printf("\n");

		getOne=1/N[k][k];
		MultiplyRow(N,getOne,k,k);
		MultiplyRow(IDTemp,getOne,k,k);
		
		}	
	}

}

return;
}
