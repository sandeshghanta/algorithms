package vyshu;
import java.util.*;
 
public class FractionalKS  {
	
	static void max_profit(int[][] array,int wt_const,int n) {
		double sum=0;
        double max; 
		int m=wt_const; 
        int j=0;
        while(m>=0){  
            max=0;  
            for(int i=0;i<n;i++){  
                if(((double)array[1][i])/((double)array[0][i])>max){  
                    max=((double)array[1][i])/((double)array[0][i]);  
                    j=i;  
                }  
            }  
            if(array[0][j]>m){  
                System.out.println("Quantity of item number: " +(j+1)+ " added is " +m);  
                sum=sum+m*max;  
                m=-1;  
            }  
            else{  
                System.out.println("Quantity of item number: " +(j+1)+ " added is " + array[0][j]);  
                m=m-array[0][j];  
                sum=sum+(double)array[1][j];  
                array[1][j]=0;  
            }  
        }  
        System.out.println("The total profit is " + sum);
 
	}
    public static void main(String args[]){   
         
        Scanner s= new Scanner(System.in);
        System.out.println("Enter no of items: ");  
        int n=s.nextInt(); 
        int array[][]=new int[2][n+1]; 
        System.out.println("Enter the weights of each items: ");
        for(int i=0;i<n;i++){ 
            array[0][i]=s.nextInt(); 
        }
        System.out.println("Enter the values of each items: ");
        for(int i=0;i<n;i++){ 
            array[1][i]=s.nextInt();
        }
        System.out.println("Enter maximum volume of knapsack:");  
        int wt_const=s.nextInt();
        max_profit(array,wt_const,n);
    }  
}