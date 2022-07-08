// user can take input as many times as they want.
// The application will terminated when user insert 0.
// User can see a menu item & select from it.
// User can insert a number in a list.
// User can perform CRUD (Create, Read, Update, Delete) operation in the list.
// User can able to clear the list.

#include<stdio.h>

#define MAX_LENGTH 1000

int main(){
    system("cls");
    int input,index,newdata,value,length=0;
    int data[MAX_LENGTH];
    int op,temp,sum=0,last;
    float avg;

    do{
        printf("MENU\n");
        printf("-------------\n");
        printf("1.Add\n");
        printf("2.Insert\n");
        printf("3.Edit\n");
        printf("4.Delete\n");
        printf("5.Display\n");
        printf("6.Clear\n");
        printf("7.Operations (Min,Max,Sum,Avg,Sort)\n");
        printf("0.Exit\n");
        printf("-------------\n");

        printf("Enter a Menu: ");
        scanf("%d",&input);

        system("cls");

        printf("-----Result-----\n");

        switch (input)
        {
        case 0:
            printf("Program Terminated\n");
            break;
        case 1:
            //add
            printf("Enter your Data: ");
            scanf("%d",&value);
            data[length]=value;
            printf("%d Added at Index %d\n",value,length);
            length++;
            break;

        case 2:
            //insert
            printf("Please insert a index between 0-%d: ",length);
            scanf("%d",&index);
            printf("Enter the Data: ");
            scanf("%d",&newdata);

            for(int i=length;i>index;i--){
                data[i]=data[i-1];
            }
            data[index]=newdata;
             printf("%d inserted at index %d\n",newdata,index);
            length++;
            break;

        case 3:
            //edit
            printf("Please insert a index between 0-%d: ",length-1);
            scanf("%d",&index);
            printf("Enter the new Data: ");
            scanf("%d",&newdata);
            data[index]=newdata;
            printf("%d updated at index %d\n",newdata,index);
            break;

        case 4:
            //delete
            printf("Please insert a index between 0-%d: ",length-1);
            scanf("%d",&index);
            for(int i=index;i<length-1;i++){
                data[i]=data[i+1];
            }
            length--;
            printf("%d Deleted from index %d\n",data[index],index);
            break;

        case 5: 
            //display
            if(length==0){
                printf("There is no Data\n");
            }else{
                printf("DATA: ");
                for(int i=0;i<length;i++){
                    printf("\t%d",data[i]);
                }
                printf("\n");
            }
            break;

        case 6: 
            //clear
            length=0;
            data[length]=0;
            printf("Data Cleared\n");
            break;

        case 7:
            // Operations
            printf("Operations\n");
            printf("----------\n");
            printf("1.Minimum\n");
            printf("2.Maximum\n");
            printf("3.Summation\n");
            printf("4.Average\n");
            printf("5.Sorting\n");
            printf("0.Exit\n");
            printf("----------\n");

            for(int i=0;i<length;i++){
                for(int j=i+1;j<length;j++){
                    if(data[i]>data[j]){
                        temp=data[i];
                        data[i]=data[j];
                        data[j]=temp;
                    }
                }
            }

            printf("Please select an operation: ");
            scanf("%d",&op);

            system("cls");

            printf("-----Result-----\n");
            switch(op){
                case 0:
                    break;

                case 1:
                    // Minimum
                    printf("Minimum data is %d\n",data[0]);
                    break;

                case 2:
                    // Maximum
                    printf("Maximum data is %d\n",data[length-1]);
                    break;

                case 3:
                    // Summation
                    for(int i=0;i<length;i++){
                        sum+=data[i];
                    }
                    printf("Summation of the given data is %d\n",sum);
                    break;

                case 4:
                    // Average
                    for(int i=0;i<length;i++){
                        sum+=data[i];
                    }
                    avg=sum/length;
                    printf("Average of the given data is %f\n",avg);
                    break;

                case 5:
                    printf("Sorting\n");
                    printf("---------\n");
                    printf("1.Ascending\n");
                    printf("2.Descending\n");
                    printf("0.Exit\n");
                    printf("---------\n");

                    printf("Please select an operation: ");
                    int sor;
                    scanf("%d",&sor);

                    system("cls");

                    printf("-----Result-----\n");
                    switch (sor)
                    {
                    case 0:
                        break;

                    case 1:
                        //printf("Ascending order is: ");
                        printf("DATA: ");
                        for(int i=0;i<length;i++){
                            printf("\t%d",data[i]);
                        }
                        printf("\n");
                            break;

                    case 2:
                        //printf("Descending order is: ");
                        printf("DATA: ");
                        for(int i=length-1;i>=0;i--){
                            printf("\t%d",data[i]);
                        }
                        printf("\n");
                        break;
                    
                    default:
                        printf("Please enter a valid operation\n");
                        break;
                    }


                break;


                default:
                        printf("Please enter a valid operation\n");
                        break;
            }


            break;
        default:
            printf("Invalid Menu No\nPlease select a valid Menu No.\n");
            break;
        }

        printf("-----Result End-----\n");

    }while(input!=0);

    system("cls");
    printf("Thanks for using our Application\n");

    return 0;
}