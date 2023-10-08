#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *x,char *y){
	char temp = *x;
	*x = *y;
	*y = temp;
}
int main(int argc, char *argv[])
{
	/*0 is false, 1 is true*/
	FILE *fileptr;
	char line[10000], rotate[2];
	int i,j;
	int red, green, same;
	char userTurn = 'R';
	char sameBoardArray[4][9] = {{'1','2','3','4','5','6','7','8','9'},{'1','2','3','4','5','6','7','8','9'},{'1','2','3','4','5','6','7','8','9'},{'1','2','3','4','5','6','7','8','9'}};
	char boardArray[4][9] = {{'1','2','3','4','5','6','7','8','9'},{'1','2','3','4','5','6','7','8','9'},{'1','2','3','4','5','6','7','8','9'},{'1','2','3','4','5','6','7','8','9'}};
	fileptr= fopen(argv[1],"r");
	red = 0;
	green = 0;
	same = 0;

	while (fgets(line, sizeof(line), fileptr)) {
		int col,row;
		int rotateIndex;
		int twoDArrayIndex;
		char twoDArray[3][3];
		/*int sixbysixArrayIndex;*/
		char sixbysixArray[6][6];
		sscanf(line, "%d:%d %s",&i, &j, rotate);
		boardArray[i-1][j-1] = userTurn;
		rotateIndex = atoi(rotate)-1;
		twoDArrayIndex = 0;
		/*sixbysixArrayIndex = 0;*/
		
		/* 3x3
		convert the 1d array into a temp 2d array
		for rotation board
		*/
		for(col = 0;col < 3; col++){
			for(row = 0;row < 3; row++){
				twoDArray[col][row]= boardArray[rotateIndex][twoDArrayIndex];
				twoDArrayIndex++;
			}
		}
		/* 6x6
		convert the 1d array into a temp 2d array for whole board to check win cases
		*/
		sixbysixArray[0][0]= boardArray[1][0];
		sixbysixArray[0][1]= boardArray[1][1];
		sixbysixArray[0][2]= boardArray[1][2];
		sixbysixArray[0][3]= boardArray[0][0];
		sixbysixArray[0][4]= boardArray[0][1];
		sixbysixArray[0][5]= boardArray[0][2];

		sixbysixArray[1][0]= boardArray[1][3];
		sixbysixArray[1][1]= boardArray[1][4];
		sixbysixArray[1][2]= boardArray[1][5];
		sixbysixArray[1][3]= boardArray[0][3];
		sixbysixArray[1][4]= boardArray[0][4];
		sixbysixArray[1][5]= boardArray[0][5];

		sixbysixArray[2][0]= boardArray[1][6];
		sixbysixArray[2][1]= boardArray[1][7];
		sixbysixArray[2][2]= boardArray[1][8];
		sixbysixArray[2][3]= boardArray[0][6];
		sixbysixArray[2][4]= boardArray[0][7];
		sixbysixArray[2][5]= boardArray[0][8];

		sixbysixArray[3][0]= boardArray[2][0];
		sixbysixArray[3][1]= boardArray[2][1];
		sixbysixArray[3][2]= boardArray[2][2];
		sixbysixArray[3][3]= boardArray[3][0];
		sixbysixArray[3][4]= boardArray[3][1];
		sixbysixArray[3][5]= boardArray[3][2];

		sixbysixArray[4][0]= boardArray[2][3];
		sixbysixArray[4][1]= boardArray[2][4];
		sixbysixArray[4][2]= boardArray[2][5];
		sixbysixArray[4][3]= boardArray[3][3];
		sixbysixArray[4][4]= boardArray[3][4];
		sixbysixArray[4][5]= boardArray[3][5];

		sixbysixArray[5][0]= boardArray[2][6];
		sixbysixArray[5][1]= boardArray[2][7];
		sixbysixArray[5][2]= boardArray[2][8];
		sixbysixArray[5][3]= boardArray[3][6];
		sixbysixArray[5][4]= boardArray[3][7];
		sixbysixArray[5][5]= boardArray[3][8];
		
		/*check win conditon after input*/
		/*check horizontal*/
		for ( col = 0; col < 6; col++){
			for ( row = 0; row < 2; row++){
				if (sixbysixArray[col][row] == 'R'){
					if(sixbysixArray[col][row]=='R'&&sixbysixArray[col][row+1]=='R'&&sixbysixArray[col][row+2]=='R'&&sixbysixArray[col][row+3]=='R'&&sixbysixArray[col][row+4]=='R'){
						red = 1;
						break;
					}
				}
				if (sixbysixArray[col][row] == 'G')
				{
					if(sixbysixArray[col][row]=='G'&&sixbysixArray[col][row+1]=='G'&&sixbysixArray[col][row+2]=='G'&&sixbysixArray[col][row+3]=='G'&&sixbysixArray[col][row+4]=='G'){
						green = 1;
						break;
					}
				}	
			}

			if(red == 1 || green == 1 ){
				break;
			}
		}
		if(red == 1 || green == 1 ){
			break;
		}
		/*check vertical*/
		for (col = 0; col < 6; col++) {
        	for ( row = 0; row < 2; row++) {
				if (sixbysixArray[row][col] == 'R') {
					if (sixbysixArray[row][col] == 'R' && sixbysixArray[row + 1][col] == 'R' &&
						sixbysixArray[row + 2][col] == 'R' && sixbysixArray[row + 3][col] == 'R' &&
						sixbysixArray[row + 4][col] == 'R') {
						red = 1;
						break;
					}
				}
				if (sixbysixArray[row][col] == 'G') {
					if (sixbysixArray[row][col] == 'G' && sixbysixArray[row+1][col] == 'G' &&sixbysixArray[row + 2][col] == 'G' && sixbysixArray[row + 3][col] == 'G' &&
						sixbysixArray[row + 4][col] == 'G') {
						green = 1;
						break;
					}
				}
        	}

			if (red == 1 || green == 1) {
				break;
			}
    	}
		if(red == 1 || green == 1 ){
			break;
		}
		/*check diagonally left top to bottom right*/
		for (col = 0; col < 2; col++){
			for (row= 0; row < 2; row++){
				if (sixbysixArray[col][row] == 'R'){
					if(sixbysixArray[col][row]=='R'&&sixbysixArray[col+1][row+1]=='R'&&sixbysixArray[col+2][row+2]=='R'&&sixbysixArray[col+3][row+3]=='R'&&sixbysixArray[col+4][row+4]=='R'){
						red = 1;
						break;
					}
				}
				if (sixbysixArray[col][row] == 'G'){
					if(sixbysixArray[col][row]=='G'&&sixbysixArray[col+1][row+1]=='G'&&sixbysixArray[col+2][row+2]=='G'&&sixbysixArray[col+3][row+3]=='G'&&sixbysixArray[col+4][row+4]=='G'){
						green = 1;
						break;
						}
					}
			}
			if(red == 1 || green == 1 ){
				break;
			}

		}	
		if(red == 1 || green == 1 ){
			break;
		}
		/*check diagonally left bottom to top right*/
		for (col = 0; col < 2; col++){
			for (row= 0; row < 2; row++){
				if (sixbysixArray[5-col][row] == 'R'){
					if(sixbysixArray[5-col][row]=='R'&&sixbysixArray[4-col][row+1]=='R'&&sixbysixArray[3-col][row+2]=='R'&&sixbysixArray[2-col][row+3]=='R'&&sixbysixArray[1-col][row+4]=='R'){
						red = 1;
						break;
					}
				}
				if (sixbysixArray[5-col][row] == 'G'){
					if(sixbysixArray[5-col][row]=='G'&&sixbysixArray[4-col][row+1]=='G'&&sixbysixArray[3-col][row+2]=='G'&&sixbysixArray[2-col][row+3]=='G'&&sixbysixArray[1-col][row+4]=='G'){
						green = 1;
						break;
						}
					}
			}
			if(red == 1 || green == 1 ){
				break;
			}

		}	
		if(red == 1 || green == 1 ){
			break;
		}


		twoDArrayIndex = 0;
		/*+ is counterclockwise rotation*/
		/*counterclockwise rotation: transpose and then reverse columns*/
		/*clockwise rotation: transpose and then reverse rows*/
		if(rotate[1]=='+'){

			/*Reverse the order of the rows*/
			for (col = 0; col < 3; col++) {
        		for (row = 0; row < 3 / 2; row++) {
            		swap(&twoDArray[col][row], &twoDArray[col][2 - row]);
        		}
    		}

    		/* Transpose the array (swap rows and columns)*/
    		for (col = 0; col < 3; col++) {
        		for (row = col; row < 3; row++) {
            		swap(&twoDArray[col][row], &twoDArray[row][col]);
        		}
    		}
			/*convert the 2d array into the 1d array*/
			for(col = 0;col < 3; col++){
				for (row = 0; row < 3; row++){
					boardArray[rotateIndex][twoDArrayIndex] = twoDArray[col][row];
					twoDArrayIndex++;
				}
			}

		}else{
			/* Reverse the order of the columns*/
    		for (col = 0; col < 3 / 2; col++) {
        		for (row = 0; row < 3; row++) {
           	 		swap(&twoDArray[col][row], &twoDArray[2 - col][row]);
        		}
    		}

    		/* Transpose the array (swap rows and columns)*/
    		for (col = 0; col < 3; col++) {
        		for (row = col; row < 3; row++) {
            		swap(&twoDArray[col][row], &twoDArray[row][col]);
        		}
    		}
			/*convert the 2d array into the 1d array*/
			for(col = 0;col < 3; col++){
				for (row = 0; row < 3; row++){
					boardArray[rotateIndex][twoDArrayIndex] = twoDArray[col][row];
					twoDArrayIndex++;
				}
			}
			

		}

		/* 6x6
		convert the 1d array into a temp 2d array for whole board to check win cases
		*/
		sixbysixArray[0][0]= boardArray[1][0];
		sixbysixArray[0][1]= boardArray[1][1];
		sixbysixArray[0][2]= boardArray[1][2];
		sixbysixArray[0][3]= boardArray[0][0];
		sixbysixArray[0][4]= boardArray[0][1];
		sixbysixArray[0][5]= boardArray[0][2];

		sixbysixArray[1][0]= boardArray[1][3];
		sixbysixArray[1][1]= boardArray[1][4];
		sixbysixArray[1][2]= boardArray[1][5];
		sixbysixArray[1][3]= boardArray[0][3];
		sixbysixArray[1][4]= boardArray[0][4];
		sixbysixArray[1][5]= boardArray[0][5];

		sixbysixArray[2][0]= boardArray[1][6];
		sixbysixArray[2][1]= boardArray[1][7];
		sixbysixArray[2][2]= boardArray[1][8];
		sixbysixArray[2][3]= boardArray[0][6];
		sixbysixArray[2][4]= boardArray[0][7];
		sixbysixArray[2][5]= boardArray[0][8];

		sixbysixArray[3][0]= boardArray[2][0];
		sixbysixArray[3][1]= boardArray[2][1];
		sixbysixArray[3][2]= boardArray[2][2];
		sixbysixArray[3][3]= boardArray[3][0];
		sixbysixArray[3][4]= boardArray[3][1];
		sixbysixArray[3][5]= boardArray[3][2];

		sixbysixArray[4][0]= boardArray[2][3];
		sixbysixArray[4][1]= boardArray[2][4];
		sixbysixArray[4][2]= boardArray[2][5];
		sixbysixArray[4][3]= boardArray[3][3];
		sixbysixArray[4][4]= boardArray[3][4];
		sixbysixArray[4][5]= boardArray[3][5];

		sixbysixArray[5][0]= boardArray[2][6];
		sixbysixArray[5][1]= boardArray[2][7];
		sixbysixArray[5][2]= boardArray[2][8];
		sixbysixArray[5][3]= boardArray[3][6];
		sixbysixArray[5][4]= boardArray[3][7];
		sixbysixArray[5][5]= boardArray[3][8];
		
		/*check win cases after rotate*/
		/*check horizontal*/
		for ( col = 0; col < 6; col++){
			for ( row = 0; row < 2; row++){
				if (sixbysixArray[col][row] == 'R'){
					if(sixbysixArray[col][row]=='R'&&sixbysixArray[col][row+1]=='R'&&sixbysixArray[col][row+2]=='R'&&sixbysixArray[col][row+3]=='R'&&sixbysixArray[col][row+4]=='R'){
						red = 1;
					}
				}
				if (sixbysixArray[col][row] == 'G')
				{
					if(sixbysixArray[col][row]=='G'&&sixbysixArray[col][row+1]=='G'&&sixbysixArray[col][row+2]=='G'&&sixbysixArray[col][row+3]=='G'&&sixbysixArray[col][row+4]=='G'){
						green = 1;
					}
				}	
			}
			/*
			if(red == 1 || green == 1 ){
				break;
			}*/
		}
		/*
		if(red == 1 || green == 1 ){
			break;
		}*/
		/*check vertical*/
		for (col = 0; col < 6; col++) {
        	for ( row = 0; row < 2; row++) {
				if (sixbysixArray[row][col] == 'R') {
					if (sixbysixArray[row][col] == 'R' && sixbysixArray[row + 1][col] == 'R' &&
						sixbysixArray[row + 2][col] == 'R' && sixbysixArray[row + 3][col] == 'R' &&
						sixbysixArray[row + 4][col] == 'R') {
						red = 1;
					}
				}
				if (sixbysixArray[row][col] == 'G') {
					if (sixbysixArray[row][col] == 'G' && sixbysixArray[row+1][col] == 'G' &&sixbysixArray[row + 2][col] == 'G' && sixbysixArray[row + 3][col] == 'G' &&
						sixbysixArray[row + 4][col] == 'G') {
						green = 1;
					}
				}
        	}
			/*
			if (red == 1 || green == 1) {
				break;
			}*/
    	}
		/*
		if(red == 1 || green == 1 ){
			break;
		}
		*/
		/*check diagonally left top to bottom right*/
		for (col = 0; col < 2; col++){
			for (row= 0; row < 2; row++){
				if (sixbysixArray[col][row] == 'R'){
					if(sixbysixArray[col][row]=='R'&&sixbysixArray[col+1][row+1]=='R'&&sixbysixArray[col+2][row+2]=='R'&&sixbysixArray[col+3][row+3]=='R'&&sixbysixArray[col+4][row+4]=='R'){
						red = 1;
					}
				}
				if (sixbysixArray[col][row] == 'G'){
					if(sixbysixArray[col][row]=='G'&&sixbysixArray[col+1][row+1]=='G'&&sixbysixArray[col+2][row+2]=='G'&&sixbysixArray[col+3][row+3]=='G'&&sixbysixArray[col+4][row+4]=='G'){
						green = 1;
						}
					}
			}
			/*
			if(red == 1 || green == 1 ){
				break;
			}*/

		}	
		/*
		if(red == 1 || green == 1 ){
			break;
		}*/
		/*check diagonally left bottom to top right*/
		for (col = 0; col < 2; col++){
			for (row= 0; row < 2; row++){
				if (sixbysixArray[5-col][row] == 'R'){
					if(sixbysixArray[5-col][row]=='R'&&sixbysixArray[4-col][row+1]=='R'&&sixbysixArray[3-col][row+2]=='R'&&sixbysixArray[2-col][row+3]=='R'&&sixbysixArray[1-col][row+4]=='R'){
						red = 1;
					}
				}
				if (sixbysixArray[5-col][row] == 'G'){
					if(sixbysixArray[5-col][row]=='G'&&sixbysixArray[4-col][row+1]=='G'&&sixbysixArray[3-col][row+2]=='G'&&sixbysixArray[2-col][row+3]=='G'&&sixbysixArray[1-col][row+4]=='G'){
						green = 1;
						}
					}
			}
			/*
			if(red == 1 || green == 1 ){
				break;
			}
			*/

		}	
		if(red == 1 || green == 1 ){
			break;
		}


		/*check who's turn it is*/
		if(userTurn == 'R'){
			userTurn = 'G';
		}else if (userTurn == 'G'){
			userTurn = 'R';
		}
		
	}
	
	fclose(fileptr);

	for(i =0; i<4;i++){
		for(j =0; j<9;j++){
			if(boardArray[i][j] != 'R' && boardArray[i][j] != 'G'){
				boardArray[i][j] = j+1+'0';
				/*printf("%c\n",boardArray[i][j]);*/

			}
		}
	}
	


	/*print board*/
	printf("   B2      B1\n");
	printf("+-------+-------+\n");
	printf("| %c %c %c | %c %c %c |\n",boardArray[1][0],boardArray[1][1],boardArray[1][2],boardArray[0][0],boardArray[0][1],boardArray[0][2]);
	printf("| %c %c %c | %c %c %c |\n",boardArray[1][3],boardArray[1][4],boardArray[1][5],boardArray[0][3],boardArray[0][4],boardArray[0][5]);
	printf("| %c %c %c | %c %c %c |\n",boardArray[1][6],boardArray[1][7],boardArray[1][8],boardArray[0][6],boardArray[0][7],boardArray[0][8]);

	printf("+-------+-------+\n");
	printf("| %c %c %c | %c %c %c |\n",boardArray[2][0],boardArray[2][1],boardArray[2][2],boardArray[3][0],boardArray[3][1],boardArray[3][2]);
	printf("| %c %c %c | %c %c %c |\n",boardArray[2][3],boardArray[2][4],boardArray[2][5],boardArray[3][3],boardArray[3][4],boardArray[3][5]);
	printf("| %c %c %c | %c %c %c |\n",boardArray[2][6],boardArray[2][7],boardArray[2][8],boardArray[3][6],boardArray[3][7],boardArray[3][8]);

	printf("+-------+-------+\n");	
	printf("   B3      B4\n");

	/*check if its the same board with no changes*/
	for ( i = 0; i < 3; i++)
	{
		for ( j = 0; j < 9; j++)
		{
			if(sameBoardArray[i][j] == boardArray[i][j]){
				same = 0;
			}
		}
		
	}
	

	if(red == 1 && green == 1 ){
		printf("It's a tie.\n");
	}else if(red == 1){
		printf("Red wins!\n");
	}else if(green == 1){
		printf("Green wins!\n");
	}else if(red == 0 && green == 0 && same==0){
		printf("It's a tie.\n");
	}
	(void)argc;
	return 0;
	
}


