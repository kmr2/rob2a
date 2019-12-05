typedef struct Cords{
	int row;
	int col;
	char letter1;
	float number;
}Cords;


task main()
{
	writeDebugStream("This is the size of each struct in bites = %d bites\n",sizeof(Cords));
	Cords array_of_cords[10];
	for(int i =0;i<10;i++){
			array_of_cords[i].row=i;
			array_of_cords[i].col=i+11;
			array_of_cords[i].letter1 = 'a'+i;
			array_of_cords[i].number = 2.345+i;
	}
	Cords *ptr = &array_of_cords;
	for(int k=0;k<10;k++){

	writeDebugStream("With pointers (x,y):%d,%d, The char = %c,The floating number = %f \n",ptr->row,ptr->col,ptr->letter1,ptr->number);
	writeDebugStream("This is the memory address of pointer = %d \n",ptr);

	writeDebugStream(" (x,y):%d,%d,%c,%f \n",ptr->row,ptr->col,ptr->letter1,ptr->number);
	*ptr++;
	}
	*ptr--
	for(int k=10;k>0;k--){
	writeDebugStream(" (x,y):%d,%d,%c,%f \n",ptr->row,ptr->col,ptr->letter1,ptr->number);
	*ptr--;
	}
	ptr = NULL;
		for(int i=0;i<10;i++){
	writeDebugStream("with array index (x,y):%d,%d, The char = %c, The floating number = %f \n",array_of_cords[i].row,array_of_cords[i].col,array_of_cords[i].letter1,array_of_cords[i].number);
	writeDebugStream("This is the memory address of the array= %d \n",&array_of_cords[i]);
	}

	writeDebugStream("%d",(int)'a');

}
