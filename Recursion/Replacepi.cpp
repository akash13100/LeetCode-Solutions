void ReplacePi(char *input)
{
     if(strlen(input)== 0)
         return; // Return from this statement.
    
    ReplacePi(input+1); // Make the recusrive call;
    if(input[0]=='p' && input[1]=='i')
    {
        for(int i= (int)strlen(input)+2;i>=2;i--)
            input[i]=input[i-2];
        input[0]='3';
        input[1]='.';
        input[2]='1';
        input[3]='4';
    }
}
