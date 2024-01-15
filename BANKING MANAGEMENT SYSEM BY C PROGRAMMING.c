/* ******* DOCUMENTATION SECTION FOR THIS PROJECT **********
 
 
 This project(banking management system) is used to provide many service for the customer. 
 first of all it is used for saving money from extravagance by creating an account number for the customer and 
 the customer is using by their account number to deposit money,to withdraw money, to transfer money and 
 although by using their ATMcard and CBEbirr the customers use depositing ,withdrawal,transfering,and 
 also topup airtime by phone number who registered in this program while we add the customer to the system and etc. 
 The  steps we use in this program is first we add the employer on banking system by getting help from the manager of bank and 
 then by using employer username and password we add a customer by using manual banking system option that exist in bellow and 
 finally by using customer phone number and account number we can create ATMcard and also we can create CBEbirr for the customer.
 We use above twenty user-defined function and there are four  main user-defined function, those are: bankManager(),Manual_system(),
 ATMcard() and  CBEbirr(). This banking management system project is free from interest.In addition to the above one when we use the same account number, pin number, username and password for different employee and also for different customer this system is not allow.
 
                         
                          ============= LIMITATION =========
                          1:This project is some percent has a limitation in validation part
                          2:Although it is free from interest 
                          =============            =========
  
 
			  *=========           BULE HORA UNIVERSITY        ************
			  *========          COLLAGE OF INFORMATICS          **********
			  *=======     DEPARTEMENT OF SOFTWARE ENGINEERING      *******
			  *=======      COURSE TITLE: SYSTEM PROGRAMMING          *****
			  *======       COURSE CODE : SwEng-3072                  *****
			  *=====     PROJECT TITLE  : BANKING MANAGEMENT SYSTEM    ****
			  *===                                                     ****
			  *===                      GROUP ONE(1)                   ****                           
			  *===                                                     ****
			  *===      NAME                       ID            **********
			  *==                                                **********
			  *==       Lelisa Shashura            Ru-0976/12    **********
			  *==       Barie  Wakjira             Ru-1351/12    **********
			  *==       Seblewengel Tsegaye        Ru-0181/12    **********
			  *==                                                **********
			  *==                                                **********
			  *==                                                **********
			  *==                 submitted date:13/06/2014 E.C  **********
			  *==                 submited  to  :Selamu Sh.      **********
			  *************************************************************
			  DEVELOPERS :group one(1) software engineering departement students*/

// The password we use to use this system is ="cprogramming"
/* one thing i would like to mention is manager username="lshashura"
                                         manager password="lelisa123*"
                                         */

/* LINK SECTION */
#include<stdio.h>

#include<stdlib.h>

#include<string.h>

/*function declaration section*/
void Manual_system();
void addCustomer();
void viewCustomerList();
void depositMoney();
void seeBalance();
void withdrawMoney();
void transferMoney();
void ATMcard();
void CBEbirr();
void login();
void moreoptions();
void searchCustomer();
void updateCustomerinfo();
void deleteCustomerinfo();
void addEmployer();
void bankManager();
void employerList();
void searchEmployer();
void updateEmployerinfo();
void deleteEmployerinfo();
void createATMcard();
void viewCustomerListbyemp();
char managerUsername[25] = "lshashura"; // global variable declaration and also initialization
char managerPassword[25] = "lelisa123*"; // global variable declaration and also initialization
int numberofcustomer = 0; // global variable declaration and also initialization
int numberofemployer = 0; //global variable declaration and also initialization

/*we use structure to save memory space rather than union */
struct information {
  //variable declaration and definition part in the structure for customers and employers
  char fristname[25], fathername[25], lastname[25], username[25], password[25];
  char work[25], date[12], gender[7];
  char citizenship[25], region[25], zone[25], woreda[25];
  int age, pin, CBEpin;
  long int account_number, phone_number, phone;
  float initialize, deposit, amount, withdraw, transfer, charge;
};
struct information cust[10000]; //This is assign how many customer can be register on banking system of this project
struct information emp[100]; //This is assign how many employer can be register on banking system of this project

int main() { //starting with main function
  int choice, result;
  /*char get_pass[25];
  char enter[25] = "cprogramming"; // This the password we used to enter the system
  printf("\nEnter password to use banking system\n");
  printf("\n...");
  scanf("%s", get_pass);
  result = strcmp(get_pass, enter); //using string compare to compare get password from user if password is correct result is return to 0.
    while (result != 0) {
    printf("\nEnter 0 to exit");
    printf("\nYour password is invalid,try again\n");
    printf("\n...");
    scanf("%s", get_pass);
    result = strcmp(get_pass, enter);
    system("clear"); // system clear screen is used to clear the screen for user to use in simple way
  }*/

  do {
    // The following is to choose what system you want to use
    printf("\n\t\t\t=================================================");
    printf("\n\t\t\t=================================================");
    printf("\n\t\t\t                                                 ");
    printf("\n\t\t\t==== WELL COME TO USE BANKING SYSTEM WITH US  ===");
    printf("\n\t\t\t                                                 ");
    printf("\n\t\t\t=================================================");
    printf("\n\t\t\t=================================================");
    printf("\n\t\t\t                                          =======");
    printf("\n\t\t\t                                          =======");
    printf("\n\t\t\t1:To get help from manager of banking     =======");
    printf("\n\t\t\t2:To use Manual banking system            =======");
    printf("\n\t\t\t3:To use ATM card system                  =======");
    printf("\n\t\t\t4:To use CBEBirr system                   =======");
    printf("\n\t\t\t0:To exit                                 =======");
    printf("\n\t\t\t=================================================");
    printf("\n\t\t\t=================================================");
    printf("\n\t\t\tEnter your choice:");
    scanf("%d", & choice);
    //The following is function calling by using switch statements
    switch (choice) {
    case 1:
      system("clear");
      bankManager();
      break;
    case 2:
      system("clear");
      Manual_system();
      break;
    case 3:
      system("clear");
      ATMcard();
      break;
    case 4:
      system("clear");
      CBEbirr();
      break;
    case 0:
      exit(0);
      break;
    default:
      printf("\ninvalid choice\n");
    }

  } while (choice != 0);
}
void bankManager() { //This function defines the simple role of manager in banking system
  int choice;
  char username[25], password[25];
  printf("\n\t\t\t=====================");
  printf("\n\t\t\tAre you a manager?===");
  printf("\n\t\t\t1:Yes            ====");
  printf("\n\t\t\t2:No             ====");
  printf("\n\t\t\t=====================");
  printf("\n\t\t\t... ");
  scanf("%d", & choice);
  switch (choice) {
  case 1:
    printf("\nenter manager username:");
    scanf("%s", username);
    printf("\nenter manager password:");
    scanf("%s", password);
    // strcmp is used for comparing two string and if two of them are equal it returns to 0.
    int user = strcmp(username, managerUsername);
    int pass = strcmp(password, managerPassword);
    if (user == 0 && pass == 0) {

      int option;
      do {
        printf("\n\t\t\t===================================");
        printf("\n\t\t\t1:to add employee              ====");
        printf("\n\t\t\t2:to view employeelist         ====");
        printf("\n\t\t\t3:to see customer list         ====");
        printf("\n\t\t\t4:to search employee           ====");
        printf("\n\t\t\t5:to update employee info      ====");
        printf("\n\t\t\t6:to delete employee info      ====");
        printf("\n\t\t\t7:to backmenu                  ====");
        printf("\n\t\t\t====================================");
        printf("\n\t\t\t...");
        scanf("%d", & option);
        system("clear");
        switch (option) {
        case 1:
          addEmployer();
          break;
          system("clear");
        case 2:
          employerList();
          break;
        case 3:
          viewCustomerList();
            break;
          system("clear");
        case 4:
          searchEmployer();
          break;
          system("clear");
        case 5:
          updateEmployerinfo();
          break;
          system("clear");
        case 6:
          deleteEmployerinfo();
          break;
          system("clear");
        case 7:
          main();
          break;
          system("clear");
        default:
          if (option < 1 || option > 7) {
            printf("\n INVALID option\n");
          }
        }
      } while (option != 0);
    } else {
      printf("\n NOT MATCH\n");
    }
    break;
  case 2:
    main();
    break;
  default:
    if (choice < 1 || choice > 2) {
      printf("\n INVALID option\n");
    }
  }

}
void addEmployer() { //Function used to add employer to the banking system by manager
  int number;
  printf("\n enter number of employer you want to register:");
  scanf("%d", & number);
  for (int i = 0; i < number; i++) {
    printf("\n enter information of employer %d:", i + 1);
    printf("\n*********************************");
    printf("\n enter frist name of employer:");
    scanf("%s", emp[numberofemployer].fristname);
    printf("\n enter father name of employer:");
    scanf("%s", emp[numberofemployer].fathername);
    printf("\n enter last name of employer:");
    scanf("%s", emp[numberofemployer].lastname);
    printf("\n enter age of employer:");
    scanf("%d", & emp[numberofemployer].age);
    printf("\n enter gender of employer:");
    scanf("%s", emp[numberofemployer].gender);
    printf("\nenter citizenship of employer:");
    scanf("%s", emp[numberofemployer].citizenship);
    printf("\nenter region of employer:");
    scanf("%s", emp[numberofemployer].region);
    printf("\nenter zone of employer:");
    scanf("%s", emp[numberofemployer].zone);
    printf("\nenter woreda of employer:");
    scanf("%s", emp[numberofemployer].woreda);
    printf("\n enter phone number of the employer:");
    scanf("%lu", & emp[numberofemployer].phone);
    printf("\nenter  username for employer:");
    scanf("%s", emp[numberofemployer].username);
    int result=strcmp(managerUsername,emp[numberofemployer].username);
  
	    int k=0;
	    while(result==0){
	    printf("\n please change employer username\n");
	    scanf("%s", emp[numberofemployer].username);
	    result=strcmp(managerUsername,emp[numberofemployer].username);
	    k++;
	    }  
    for (int j = 0; j < numberofemployer; j++) {
      // strcmp is used for comparing two string and if two of them are equal it returns to 0.
      int user_n = strcmp(emp[numberofemployer].username, emp[j].username);
      if (user_n == 0) {
        int z = 0;
        while (user_n == 0) {
          printf("\nenter new username for employer the frist one is exist:");
          scanf("%s", emp[numberofemployer].username);
          system("clear");
          user_n = strcmp(emp[numberofemployer].username, emp[j].username);
          z++;
        }
      }
    }
    printf("\nenter  password for employer:");
    scanf("%s", emp[numberofemployer].password);
    
     int resu=strcmp(managerPassword,emp[numberofemployer].password);
  
	    int h=0;
	    while(resu==0){
	    printf("\n please change employer username\n");
	    scanf("%s", emp[numberofemployer].password);
	    result=strcmp(managerPassword,emp[numberofemployer].password);
	    h++;
	    }  
    for (int j = 0; j < numberofemployer; j++) {
      // strcmp is used for comparing two string and if two of them are equal it returns to 0.
      int user_n = strcmp(emp[numberofemployer].password, emp[j].password);
      if (user_n == 0) {
        int z = 0;
        while (user_n == 0) {
          printf("\nenter new password for employer the frist one is exist:");
          scanf("%s", emp[numberofemployer].password);
          system("clear");
          user_n = strcmp(emp[numberofemployer].password, emp[j].password);
          z++;
        }
      }
    }
    
    numberofemployer++;
   system("clear");
  printf("\nREGISTERED succesfully");
  }
}

void searchEmployer() { //This function used to search employee from the list by manager
  char username[25], password[25];
  if (numberofemployer == 0) {
    printf("\n\t\t EMPLOYER NOT EXIST\n");
  } else {
    printf("\nenter  username of employer:");
    scanf("%s", username);
    printf("\nenter  password of employer:");
    scanf("%s", password);
    for (int i = 0; i < numberofemployer; i++) {
      int user = strcmp(username, emp[i].username);
      int pass = strcmp(password, emp[i].password);
      if (user == 0 && pass == 0) {
        printf("\n\t\t======================================");
        printf("\n\t\tThe information of employer %d:=======", i + 1);
        printf("\n\t\t======================================");
        printf("\n\t\tFrist name:   %s", emp[i].fristname);
        printf("\n\t\tFather name:  %s", emp[i].fathername);
        printf("\n\t\tLast name:    %s", emp[i].lastname);
        printf("\n\t\tAge:          %d", emp[i].age);
        printf("\n\t\tGender:       %s", emp[i].gender);
        printf("\n\t\tCitizenship:  %s", emp[i].citizenship);
        printf("\n\t\tRegion:       %s", emp[i].region);
        printf("\n\t\tZone:         %s", emp[i].zone);
        printf("\n\t\tWoreda:       %s", emp[i].woreda);
        printf("\n\t\tPhone number: %lu", emp[i].phone);
        printf("\n\t\tUsername is:  %s", emp[i].username);
        printf("\n\t\tPassword is:  %s", emp[i].password);
        printf("\n\t\t======================================");
      } else {
        if (i == numberofemployer - 1) {
          printf("\n INFORMATION NOT MATCH\n");
        }
      }
    }
  }
}
void updateEmployerinfo() { //This function used to update the information of employer by manager
  char username[25], password[25];
  long int phone;
  if (numberofemployer == 0) {
    printf("\n\t\t EMPLOYER NOT EXIST\n");
  } else {
    printf("\nenter  username of employer:");
    scanf("%s", username);
    printf("\nenter  password of employer:");
    scanf("%s", password);
    for (int i = 0; i < numberofemployer; i++) {
      int user = strcmp(username, emp[i].username);
      int pass = strcmp(password, emp[i].password);
      if (user == 0 && pass == 0) {
        printf("\n*********************************");
        printf("\n enter new information of employer %d:", i + 1);
        printf("\n*********************************");
        printf("\n enter phone number of the employer:");
        scanf("%lu", & phone);
        printf("\nenter  username for employer:");
        scanf("%s", username);
        printf("\nenter  password for employer:");
        scanf("%s", password);
        emp[i].phone = phone;
        strcpy(emp[i].username, username);
        strcpy(emp[i].password, password);

        printf("\nUPDATED succesfully");
        break;
      } else {
        if (i == numberofemployer - 1) {
          printf("\n INFORMATION NOT MATCH\n");
        }
      }
    }
  }
}
void deleteEmployerinfo() { //This function used to delete information of employer from the list by manager
  char username[25], password[25];
  if (numberofemployer == 0) {
    printf("\n\t\t EMPLOYER NOT EXIST\n");
  } else {
    printf("\nenter  username of employer:");
    scanf("%s", username);
    printf("\nenter  password of employer:");
    scanf("%s", password);
    for (int i = 0; i < numberofemployer; i++) {
      int user = strcmp(username, emp[i].username);
      int pass = strcmp(password, emp[i].password);
      if (user == 0 && pass == 0) {
        //strcpy is the string that used to copy one string into another
        strcpy(emp[i].fristname, emp[i + 1].fristname);
        strcpy(emp[i].fathername, emp[i + 1].fathername);
        strcpy(emp[i].lastname, emp[i + 1].lastname);
        emp[i].age = emp[i + 1].age;
        strcpy(emp[i].gender, emp[i + 1].gender);
        strcpy(emp[i].citizenship, emp[i + 1].citizenship);
        strcpy(emp[i].region, emp[i + 1].region);
        strcpy(emp[i].zone, emp[i + 1].zone);
        strcpy(emp[i].woreda, emp[i + 1].woreda);
        emp[i].phone = emp[i + 1].phone;
        strcpy(emp[i].username, emp[i + 1].username);
        strcpy(emp[i].password, emp[i + 1].password);
        numberofemployer--; //numberofemployer-- is used to decrease number of employer from the list when we delete employer information
        printf("\n DELETED succesfully");
        break;
      } else {
        if (i == numberofemployer - 1) {
          printf("\n INFORMATION NOT MATCH\n");
        }
      }
    }
  }
}
void employerList() { //This function display all employer to a manager
  system("clear");
  if (numberofemployer == 0) {
    printf("\n\t\t EMPLOYER NOT EXIST\n");
  } else {
    for (int i = 0; i < numberofemployer; i++) {
      printf("\n\t\t======================================");
      printf("\n\t\tThe information of employer %d:=======", i + 1);
      printf("\n\t\t======================================");
      printf("\n\t\tFrist name:    %s", emp[i].fristname);
      printf("\n\t\tFather name:   %s", emp[i].fathername);
      printf("\n\t\tLast name:     %s", emp[i].lastname);
      printf("\n\t\tAge:           %d", emp[i].age);
      printf("\n\t\tGender:        %s", emp[i].gender);
      printf("\n\t\tCitizenship:   %s", emp[i].citizenship);
      printf("\n\t\tRegion:        %s", emp[i].region);
      printf("\n\t\tZone:          %s", emp[i].zone);
      printf("\n\t\tWoreda:        %s", emp[i].woreda);
      printf("\n\t\tPhone number:  %lu", emp[i].phone);
      printf("\n\t\tUsername is:   %s", emp[i].username);
      printf("\n\t\tPassword is:   %s", emp[i].password);
      printf("\n\t\t======================================");
    }
  }
}
void Manual_system() { // to use manual system you choose the following option 
  system("clear");
  char username[30];
  char password[30];
  int choice;
  printf("\n\t\t\t========================");
  printf("\n\t\t\tAre you employer ? =====");
  printf("\n\t\t\t1:Yes              =====");
  printf("\n\t\t\t2:No               =====");
  printf("\n\t\t\t========================");
  printf("\n\t\t\t...");
  scanf("%d", & choice);
  switch (choice) {
  case 1:
    printf("\nenter employee username:\n");
    scanf("%s", username);
    printf("\nenter employee password:\n");
    scanf("%s", password);
    
    for (int i = 0; i < numberofemployer; i++) {
    int user = strcmp(username, emp[i].username);
    int pass = strcmp(password, emp[i].password);
      if (user == 0 && pass == 0) {
        printf("\nRIGHT...");
        do {
          printf("\n\t\t\t=================================================");
          printf("\n\t\t\t=================================================");
          printf("\n\t\t\t====1:To add new customer                ========");
          printf("\n\t\t\t====2:To see customer list               ========");
          printf("\n\t\t\t====3:To deposit money for customer      ========");
          printf("\n\t\t\t====4:To see customer balance            ========");
          printf("\n\t\t\t====5:To withdraw money for customer     ========");
          printf("\n\t\t\t====6:To transfer money for customer     ========");
          printf("\n\t\t\t====7:To search customer info            ========");
          printf("\n\t\t\t====8:To update customer info            ========");
          printf("\n\t\t\t====9:To delete customer info            ========");
          printf("\n\t\t\t====0:To back menu                       ========");
          printf("\n\t\t\t=================================================");
          printf("\n\t\t\t=================================================");
          printf("\n\t\t\tenter your choice:");
          scanf("%d", & choice);
          system("clear");
          switch (choice) { // function calling which we use in the manual system
          case 0:
            main();
            break;
          case 1:
            addCustomer();
            break;
          case 2:
            viewCustomerListbyemp();
            break;
          case 3:
            depositMoney();
            break;
          case 4:
            seeBalance();
            break;
          case 5:
            withdrawMoney();
            break;
          case 6:
            transferMoney();
            break;
          case 7:
            searchCustomer();
            break;
          case 8:
            updateCustomerinfo();
            break;
          case 9:
            deleteCustomerinfo();
            break;
          default:
            if (choice < 0 || choice > 10) {
              printf("\ninvalid\n");
            }
          }
        } while (1);
      } else {
        if (i == numberofemployer - 1) {
          printf("\nINFORMATION NOT MATCH\n");
        }
      }
    }
    break;
  case 2:
    main();
    break;
  default:
    if (choice < 1 || choice > 2) {
      printf("\n invalid option\n");
    }
  }
}
void addCustomer() { //function definition 
  //this function is used to add customer to banking system specifically
  int number;
  printf("\n enter number of customer you want to register:");
  scanf("%d", & number);
  for (int i = 0; i < number; i++) {
    printf("\n enter information of customer %d:", i + 1);
    printf("\n*********************************");
    printf("\nenter the date of today:");
    scanf("%s", cust[numberofcustomer].date);
    printf("\n enter frist name of customer:");
    scanf("%s", cust[numberofcustomer].fristname);
    printf("\n enter father name of customer:");
    scanf("%s", cust[numberofcustomer].fathername);
    printf("\n enter last name of customer:");
    scanf("%s", cust[numberofcustomer].lastname);
    printf("\n enter age of customer:");
    scanf("%d", & cust[numberofcustomer].age);
    printf("\n enter gender of customer:");
    scanf("%s", cust[numberofcustomer].gender);
    printf("\n enter your work:");
    scanf("%s", cust[i].work);
    printf("\nenter citizenship of cuistomer:");
    scanf("%s", cust[numberofcustomer].citizenship);
    printf("\nenter region of cuistomer:");
    scanf("%s", cust[numberofcustomer].region);
    printf("\nenter zone of cuistomer:");
    scanf("%s", cust[numberofcustomer].zone);
    printf("\nenter woreda of cuistomer:");
    scanf("%s", cust[numberofcustomer].woreda);
    printf("\n enter phone number of the customer:");
    scanf("%lu", & cust[numberofcustomer].phone_number);
    for (int j = 0; j < numberofcustomer; j++) {
      if (cust[numberofcustomer].phone_number == cust[j].phone_number) {
        int z = 0;
        while (cust[numberofcustomer].phone_number == cust[j].phone_number) {
          printf("\nThis account is created before create another\n");
          scanf("%lu", & cust[numberofcustomer].phone_number);
          system("clear");
          z++;
        }
      }
    }
    printf("\ncreate account number for the customer:");
    scanf("%lu", & cust[numberofcustomer].account_number);
    for (int j = 0; j < numberofcustomer; j++) {
      if (cust[numberofcustomer].account_number == cust[j].account_number) {
        int z = 0;
        while (cust[numberofcustomer].account_number == cust[j].account_number) {
          printf("\nThis account is created before create another\n");
          scanf("%lu", & cust[numberofcustomer].account_number);
          system("clear");
          z++;
        }
      }
    }
    printf("\n enter some amount of money to initialize your account:");
    scanf("%f", & cust[numberofcustomer].initialize);
    if (cust[numberofcustomer].initialize < 50) {
      printf("\n you can't initialize with %f amount, please try for >=50:", cust[numberofcustomer].initialize);
      scanf("%f", & cust[numberofcustomer].initialize);
      if (cust[numberofcustomer].initialize < 50) {
        printf("\n your account is not initialized.\n");
      } else {
        printf("'\n your account is succesfully created.\n");
        cust[numberofcustomer].amount = 0;
        cust[numberofcustomer].amount += cust[numberofcustomer].initialize;

      }
    } else {
      system("clear");
      printf("'\n your account is succesfully created.\n");
      cust[numberofcustomer].amount = 0;
      cust[numberofcustomer].amount += cust[numberofcustomer].initialize;
    }
    numberofcustomer++; // used to increment number of customer
  }
  system("clear");
}
void viewCustomerListbyemp(){
system("clear");
  if (numberofcustomer == 0) {
    printf("\n\t\t CUSTOMER NOT EXIST\n");
  } else {
    for (int i = 0; i < numberofcustomer; i++) {
      printf("\n\t\t======================================");
      printf("\n\t\tThe information of customer %d:=======", i + 1);
      printf("\n\t\t======================================");
      printf("\n\t\tRegistered date: %s", cust[i].date);
      printf("\n\t\tFrist name:      %s", cust[i].fristname);
      printf("\n\t\tFather name:     %s", cust[i].fathername);
      printf("\n\t\tLast name:       %s", cust[i].lastname);
      printf("\n\t\tAge:             %d", cust[i].age);
      printf("\n\t\tGender:          %s", cust[i].gender);
      printf("\n\t\tWork:            %s", cust[i].work);
      printf("\n\t\tCitizenship:     %s", cust[i].citizenship);
      printf("\n\t\tRegion:          %s", cust[i].region);
      printf("\n\t\tZone:            %s", cust[i].zone);
      printf("\n\t\tWoreda:          %s", cust[i].woreda);
      printf("\n\t\tPhone number:    %lu", cust[i].phone_number);
      printf("\n\t\t======================================");
    }
  }
}
void viewCustomerList() { // function definition used to view all customer 
  system("clear");
  if (numberofcustomer == 0) {
    printf("\n\t\t CUSTOMER NOT EXIST\n");
  } else {
    for (int i = 0; i < numberofcustomer; i++) {
      printf("\n\t\t======================================");
      printf("\n\t\tThe information of customer %d:=======", i + 1);
      printf("\n\t\t======================================");
      printf("\n\t\tRegistered date: %s", cust[i].date);
      printf("\n\t\tFrist name:      %s", cust[i].fristname);
      printf("\n\t\tFather name:     %s", cust[i].fathername);
      printf("\n\t\tLast name:       %s", cust[i].lastname);
      printf("\n\t\tAge:             %d", cust[i].age);
      printf("\n\t\tGender:          %s", cust[i].gender);
      printf("\n\t\tWork:            %s", cust[i].work);
      printf("\n\t\tCitizenship:     %s", cust[i].citizenship);
      printf("\n\t\tRegion:          %s", cust[i].region);
      printf("\n\t\tZone:            %s", cust[i].zone);
      printf("\n\t\tWoreda:          %s", cust[i].woreda);
      printf("\n\t\tAccount number:  %lu", cust[i].account_number);
      printf("\n\t\tATM PIN number:  %d", cust[i].pin);
      printf("\n\t\tCBEbirr Account: %d ", cust[i].CBEpin);
      printf("\n\t\tPhone number:    %lu", cust[i].phone_number);
      printf("\n\t\t======================================");
    }
  }
}
void searchCustomer() { // function definition used to search customer information by account number or phone number
  system("clear");
  int option;
  long int user_account, phone_number;
  if (numberofcustomer == 0) {
    printf("\n\t\t CUSTOMER NOT EXIST\n");
  } else {
    printf("\n================================");
    printf("\n1:search by Account number =====");
    printf("\n2:search by phone number   =====");
    printf("\n================================");
    printf("\n enter option:");
    scanf("%d", & option);
    switch (option) {
    case 1:
      printf("\n enter account number of customer you want to see info:");
      scanf("%lu", & user_account);
      for (int i = 0; i < numberofcustomer; i++) {
        if (user_account == cust[i].account_number) {
          printf("\n\t\t======================================");
          printf("\n\t\tThe information of customer %d:=======", i + 1);
          printf("\n\t\t======================================");
          printf("\n\t\tRegistered date: %s", cust[i].date);
          printf("\n\t\tFrist name:      %s", cust[i].fristname);
          printf("\n\t\tFather name:     %s", cust[i].fathername);
          printf("\n\t\tLast name:       %s", cust[i].lastname);

          printf("\n\t\tAge:            %d", cust[i].age);
          printf("\n\t\tGender:         %s", cust[i].gender);
          printf("\n\t\tWork:           %s", cust[i].work);
          printf("\n\t\tCitizenship:    %s", cust[i].citizenship);
          printf("\n\t\tRegion:         %s", cust[i].region);
          printf("\n\t\tZone:           %s", cust[i].zone);
          printf("\n\t\tWoreda:         %s", cust[i].woreda);
          printf("\n\t\tPhone number:   %lu", cust[i].phone_number);
          printf("\n\t\t======================================");
          break;
        } else {
          if (i == numberofcustomer - 1) {
            printf("\ninvalid account number.\n");
          }
        }
      }
      break;
    case 2:
      printf("\n enter phone number of customer you want to see info:");
      scanf("%lu", & phone_number);
      for (int i = 0; i < numberofcustomer; i++) {
        if (phone_number == cust[i].phone_number) {
          printf("\n\t\t======================================");
          printf("\n\t\tThe information of customer %d:=======", i + 1);
          printf("\n\t\t======================================");
          printf("\n\t\tRegistered date: %s", cust[i].date);
          printf("\n\t\tFrist name:      %s", cust[i].fristname);
          printf("\n\t\tFather name:     %s", cust[i].fathername);
          printf("\n\t\tLast name:       %s", cust[i].lastname);

          printf("\n\t\tAge:             %d", cust[i].age);

          printf("\n\t\tGender:         %s", cust[i].gender);
          printf("\n\t\tWork:           %s", cust[i].work);
          printf("\n\t\tCitizenship:    %s", cust[i].citizenship);
          printf("\n\t\tRegion:         %s", cust[i].region);
          printf("\n\t\tZone:           %s", cust[i].zone);
          printf("\n\t\tWoreda:         %s", cust[i].woreda);
          
          printf("\n\t\tPhone number:%lu", cust[i].phone_number);
          printf("\n\t\t======================================");
          break;
        } else {
          if (i == numberofcustomer - 1) {
            printf("\ninvalid phone number.\n");
          }
        }
      }
      break;
    default:
      if (option < 1 || option > 2) {
        printf("\n invalid option\n");
      }
    }
  }
}
void updateCustomerinfo() { // function definition used to update customer information by account number or phone number
  system("clear");
  int option;
  char fristname[25], fathername[25], lastname[25];
  long int user_account, phone_number;
  if (numberofcustomer == 0) {
    printf("\n\t\t CUSTOMER NOT EXIST\n");
  } else {
    printf("\n================================");
    printf("\n1:update by Account number =====");
    printf("\n2:update by phone number   =====");
    printf("\n================================");
    printf("\n enter option:");
    scanf("%d", & option);
    switch (option) {
    case 1:
      printf("\n enter account number of customer you want to update info:");
      scanf("%lu", & user_account);
      for (int i = 0; i < numberofcustomer; i++) {
        if (user_account == cust[i].account_number) {
          printf("\nenter customer frist name you want to change it:");
          scanf("%s", fristname);
          printf("\nenter customer father name you want to change it:");
          scanf("%s", fathername);
          printf("\nenter customer last name you want to change it:");
          scanf("%s", lastname);
          printf("\nenter customer phone number you want to change it:");
          scanf("%lu", & phone_number);
          strcpy(cust[i].fristname, fristname);
          strcpy(cust[i].fathername, fathername);
          strcpy(cust[i].lastname, lastname);
          cust[i].phone_number = phone_number;
          printf("\n your information is succesfully updated.");
          break;
        } else {
          if (i == numberofcustomer - 1) {
            printf("\ninvalid account number.\n");
          }
        }
      }
      break;
    case 2:
      printf("\n enter phone number of customer you want to update info:");
      scanf("%lu", & phone_number);
      for (int i = 0; i < numberofcustomer; i++) {
        if (phone_number == cust[i].phone_number) {
          printf("\nenter customer frist name you want to change it:");
          scanf("%s", fristname);
          printf("\nenter customer father name you want to change it:");
          scanf("%s", fathername);
          printf("\nenter customer last name you want to change it:");
          scanf("%s", lastname);
          printf("\nenter customer phone number you want to change it:");
          scanf("%lu", & phone_number);
          strcpy(cust[i].fristname, fristname);
          strcpy(cust[i].fathername, fathername);
          strcpy(cust[i].lastname, lastname);
          cust[i].phone_number = phone_number;
          printf("\n your information is succesfully updated.");
          break;
        } else {
          if (i == numberofcustomer - 1) {
            printf("\ninvalid phone number.\n");
          }
        }
      }
      break;
    default:
      if (option < 1 || option > 2) {
        printf("\n invalid option");
      }
    }
  }
}
void deleteCustomerinfo() { // function definition used to delete customer information by account number or phone number
  system("\nclear");
  int indexofcustomer, option;
  long int account_number, phone_number;
  if (numberofcustomer == 0) {
    printf("\n\t\t CUSTOMER NOT EXIST\n");
  } else {
    printf("\n=================================");
    printf("\n1:delete by Account number =====");
    printf("\n2:delete by phone number   =====");
    printf("\n================================");
    printf("\n enter option:");
    scanf("%d", & option);
    switch (option) {
    case 1:
      printf("\n enter account number of customer you want to delete info:");
      scanf("%lu", & account_number);
      for (int i = 0; i < numberofcustomer; i++) {
        if (account_number == cust[i].account_number) {
          indexofcustomer = i;
          for (int j = indexofcustomer; j < numberofcustomer - 1; j++) {
            cust[j].account_number = cust[j + 1].account_number;
            cust[j].phone_number = cust[j + 1].phone_number;
            strcpy(cust[j].woreda, cust[j + 1].woreda);
            strcpy(cust[j].zone, cust[j + 1].zone);
            strcpy(cust[j].region, cust[j + 1].region);
            strcpy(cust[j].citizenship, cust[j + 1].citizenship);
            strcpy(cust[j].work, cust[j + 1].work);
            strcpy(cust[j].gender, cust[j + 1].gender);
            cust[j].age = cust[j + 1].age;
            strcpy(cust[j].lastname, cust[j + 1].lastname);
            strcpy(cust[j].fathername, cust[j + 1].fathername);
            strcpy(cust[j].fristname, cust[j + 1].fristname);
            strcpy(cust[j].date, cust[j + 1].date);

          }
          numberofcustomer--;
          printf("\ndeleted succesfully\n");
          break;
        } else {
          if (i == numberofcustomer - 1) {
            printf("\ninvalid account\n");
          }
        }
      }
      break;
    case 2:
      printf("\n enter phone number of customer you want to delete info:");
      scanf("%lu", & phone_number);
      for (int i = 0; i < numberofcustomer; i++) {
        if (phone_number == cust[i].phone_number) {
          indexofcustomer = i;
          for (int j = indexofcustomer; j < numberofcustomer - 1; j++) {
            cust[j].account_number = cust[j + 1].account_number;
            cust[j].phone_number = cust[j + 1].phone_number;
            strcpy(cust[j].woreda, cust[j + 1].woreda);
            strcpy(cust[j].zone, cust[j + 1].zone);
            strcpy(cust[j].region, cust[j + 1].region);
            strcpy(cust[j].citizenship, cust[j + 1].citizenship);
            strcpy(cust[j].work, cust[j + 1].work);
            strcpy(cust[j].gender, cust[j + 1].gender);
            cust[j].age = cust[j + 1].age;
            strcpy(cust[j].lastname, cust[j + 1].lastname);
            strcpy(cust[j].fathername, cust[j + 1].fathername);
            strcpy(cust[j].fristname, cust[j + 1].fristname);
            strcpy(cust[j].date, cust[j + 1].date);

          }
          numberofcustomer--;
          printf("\ndeleted succesfully\n");
          break;
        } else {
          if (i == numberofcustomer - 1) {
            printf("\ninvalid phone number\n");
          }
        }
      }
      break;
    default:
      if (option < 1 || option > 2) {
        printf("\n invalid option\n");
      }
    }
  }
}
void depositMoney() { // function definition used to deposit money by checking fristname,fathername and account number
  system("clear");
  int result;
  int res;
  char fristname[25], fathername[25];
  long int account_number;
  if (numberofcustomer == 0) {
    printf("\n\t\t CUSTOMER NOT EXIST\n");
  } else {
    printf("\n enter your frist name:");
    scanf("%s", fristname);
    printf("\n enter your father name:");
    scanf("%s", fathername);
    printf("\nenter your account number:");
    scanf("%lu", & account_number);
    for (int i = 0; i < numberofcustomer; i++) {
      result = strcmp(fristname, cust[i].fristname);
      res = strcmp(fathername, cust[i].fathername);
      if (account_number == cust[i].account_number && result == 0 && res == 0) {
        printf("\n enter amount of money you want to deposit:");
        scanf("%f", & cust[i].deposit);
        cust[i].amount += cust[i].deposit;
        printf("\n you deposited succesfully.");
        break;
      } else {
        if (i == numberofcustomer - 1) {
          printf("\nyour information is mis-match\n");
        }
      }
    }
  }
}
void seeBalance() { // function definition used to view balance  by checking fristname,fathername and account number
  system("clear");
  int result;
  int res;
  char fristname[25], fathername[25];
  long int account_number;
  if (numberofcustomer == 0) {
    printf("\n\t\t CUSTOMER NOT EXIST\n");
  } else {
    printf("\n enter your frist name:");
    scanf("%s", fristname);
    printf("\n enter your father name:");
    scanf("%s", fathername);
    printf("\nenter your account number:");
    scanf("%lu", & account_number);
    for (int i = 0; i < numberofcustomer; i++) {
      result = strcmp(fristname, cust[i].fristname);
      res = strcmp(fathername, cust[i].fathername);
      if (account_number == cust[i].account_number && result == 0 && res == 0) {
        printf("\nyour current balance from %lu is %f.", cust[i].account_number, cust[i].amount);
        break;
      } else {
        if (i == numberofcustomer - 1) {
          printf("\nyour information is mis-match\n");
        }
      }
    }
  }
}
void withdrawMoney() { // function definition used to withdraw money by checking fristname,fathername and account number
  system("clear");
  int result;
  int res;
  char fristname[25], fathername[25];
  long int account_number;
  if (numberofcustomer == 0) {
    printf("\n\t\t CUSTOMER NOT EXIST\n");
  } else {
    printf("\n enter your frist name:");
    scanf("%s", fristname);
    printf("\n enter your father name:");
    scanf("%s", fathername);
    printf("\nenter your account number:");
    scanf("%lu", & account_number);
    for (int i = 0; i < numberofcustomer; i++) {
      result = strcmp(fristname, cust[i].fristname);
      res = strcmp(fathername, cust[i].fathername);
      if (account_number == cust[i].account_number && result == 0 && res == 0) {
        printf("\nenter your withdraw amount:");
        scanf("%f", & cust[i].withdraw);
        if (cust[i].withdraw > 50 + cust[i].amount) {
          printf("\n your balance is insufficient, you have only %f money.", cust[i].amount);
        } else {
          cust[i].amount -= cust[i].withdraw;
          printf("\n you withdrawed succesfully %f amount.", cust[i].withdraw);
          break;
        }
      } else {
        if (i == numberofcustomer - 1) {
          printf("\nyour information is mis-match\n");
        }
      }
    }
  }
}
void transferMoney() { // function definition used to transfer money by checking fristname,fathername and account number
  system("clear");
  int result;
  int res;
  char fristname[25], fathername[25];
  long int account_number;
  if (numberofcustomer == 0) {
    printf("\n\t\t CUSTOMER NOT EXIST\n");
  } else {
    printf("\n enter your frist name:");
    scanf("%s", fristname);
    printf("\n enter your father name:");
    scanf("%s", fathername);
    printf("\nenter your account number:");
    scanf("%lu", & account_number);
    for (int i = 0; i < numberofcustomer; i++) {
      result = strcmp(fristname, cust[i].fristname);
      res = strcmp(fathername, cust[i].fathername);
      if (account_number == cust[i].account_number && result == 0 && res == 0) {
        printf("\n enter customer frist name:");
        scanf("%s", fristname);
        printf("\n enter customer father name:");
        scanf("%s", fathername);
        printf("\n enter account number you want to transfer it:");
        scanf("%lu", & account_number);
        if(account_number == cust[i].account_number){
        int n=0;
        while(account_number == cust[i].account_number){
        printf("\n you can't transfer to your account,please enter another:");
        scanf("%lu", & account_number);
        n++;
        }
        }
        for (int j = 0; j < numberofcustomer; j++) {
          result = strcmp(fristname, cust[j].fristname);
          res = strcmp(fathername, cust[j].fathername);
          if (account_number == cust[j].account_number && result == 0 && res == 0) {
            printf("\n please enter amount of money you want to transfer:");
            scanf("%f", & cust[i].transfer);
            if (cust[i].transfer < cust[i].amount) {
              cust[i].amount -= cust[i].transfer;
              cust[j].amount += cust[i].transfer;
              printf("\n you transfered %f money succesfully to %lu account and to user %s %s %s",
                cust[i].transfer, cust[j].account_number,
                cust[j].fristname, cust[j].fathername, cust[j].lastname);
              break;
            } else {
              printf("\n insufficient balance.");
            }
          } else {
            if (account_number != cust[j].account_number && j == numberofcustomer - j) {
              printf("\ncustomer information is mis-match\n");
            }
          }
        }
        break;
      } else {
        if (account_number != cust[i].account_number && i == numberofcustomer - 1) {
          printf("\nyour information is mis-match\n");
        }
      }
    }
  }
}
void ATMcard() {
  /*function definition that used for using ATM card system , to use ATM card frist you choose on the frist page option that says using ATM system and the know choose the foloowing option you want to use*/
  int number, choice, pin;
  long int account_number;
  do {
    printf("\n==============================");
    printf("\n Do you have an ATMcard ?=====");
    printf("\n1:Yes                    =====");
    printf("\n2:Enter 2 to register    =====");
    printf("\n3:to backmenu            =====");
    printf("\n==============================");
    printf("\n...");
    scanf("%d", & choice);
    switch (choice) {
    case 1:
      printf("\n\t\t\tenter your pin number:");
      scanf("%d", & pin);
      for (int i = 0; i < numberofcustomer; i++) {
        if (pin == cust[i].pin) {
          do { //in the bellow option there is depositing system but it is not working in our country as we know but in the future we use it
            printf("\n\t\t\t=================================================");
            printf("\n\t\t\t=================================================");
            printf("\n\t\t\t====1:To deposit money                ===========");
            printf("\n\t\t\t====2:To withdraw money               ===========");
            printf("\n\t\t\t====3:To see balance                  ===========");
            printf("\n\t\t\t====4:To transfer money               ===========");
            printf("\n\t\t\t====0:To back menu                    ===========");
            printf("\n\t\t\t=================================================");
            printf("\n\t\t\t=================================================");
            printf("\n\t\t\tenter your choice:");
            scanf("%d", & number);
            switch (number) {
            case 0:
              main();
              break;
            case 1:
              system("clear");
              printf("\n enter your deposit amount:");
              scanf("%f", & cust[i].deposit);
              cust[i].amount += cust[i].deposit;
              printf("\n you deposited succesfully.");
              break;
            case 2:

              printf("\n enter your withdraw amount:");
              scanf("%f", & cust[i].withdraw);
              if (cust[i].withdraw < cust[i].amount) {
                cust[i].amount -= cust[i].withdraw;
                printf("\n you withdrawed succesfully.");
              } else {
                printf("\n you haven't sufficient money for this service.");
              }
              break;
            case 3:
              system("clear");
              printf("\nyour current balance is %f.", cust[i].amount);
              break;
            case 4:
              system("clear");
              printf("\n enter account number of customer you want to transfer money:");
              scanf("%lu", & account_number);
              for (int j = 0; j < numberofcustomer; j++) {
                if (account_number == cust[j].account_number) {
                  printf("\n enter amount of money you want to transfer:");
                  scanf("%f", & cust[i].transfer);
                  if (cust[i].transfer >= cust[i].amount) {
                    printf("\n balance is insufficient\n");
                    break;
                  } else {
                    cust[i].amount -= cust[i].transfer;
                    cust[j].amount += cust[i].transfer;
                    printf("\nyou transfered succesfully.");
                    break;
                  }

                } else {
                  if (j == numberofcustomer - 1) {
                    printf("\ninvalid account number\n");
                  }
                }
              }
              break;
            default:
              if (number < 0 || number > 4) {
                printf("\ninvalid choice\n");
              }
            }
          } while (number != 0);
        } else {
          if (i == numberofcustomer - 1) {
            printf("\n invalid pin.");
          }
        }
      }

      break;
    case 3:
      main();
      break;
    case 2:
      createATMcard();
      break;
    default:
      if (choice < 1 || choice > 3) {
        printf("\n INVALID choice\n");
      }
    }
  } while (1);

}
void createATMcard() {
  int choice, pin,option;
  char fristname[25], fathername[25], username[25], password[25];
  long int account_num;

  printf("\n=======================================");
  printf("\nDo you have an account number ?  ======");
  printf("\n1:Yes                            ======");
  printf("\n2:Enter 2 to register            ======");
  printf("\n3:To back                        ======");
  printf("\n=======================================");
  printf("\n ...");
  scanf("%d", & choice);
  switch (choice) {
  case 1:
    printf("\n Enter employer username:");
    scanf("%s", username);
    printf("\n Enter employer password:");
    scanf("%s", password);

    for (int j = 0; j < numberofemployer; j++) {
      int uname = strcmp(username, emp[j].username);
      int pass = strcmp(password, emp[j].password);
      if (uname == 0 && pass == 0) {
      printf("\n\t\t\t RIGHT.....");
      do{
      printf("\n 1 :CREATE PIN NUMBER");
      printf("\n 2 :BACK");
      printf("\n 0 :exit");
      printf("\n ...");
      scanf("%d", &option);
      switch(option){
      
      case 1:
      
        printf("\n Enter frist name of customer:");
        scanf("%s", fristname);
        printf("\n Enter father name of customer:");
        scanf("%s", fathername);
        printf("\n Enter account number of customer:");
        scanf("%lu", & account_num);

        for (int i = 0; i < numberofcustomer; i++) {
          int fname = strcmp(fristname, cust[i].fristname);
          int fa_name = strcmp(fathername, cust[i].fathername);
          if (fname == 0 && fa_name == 0 && account_num == cust[i].account_number) {
            printf("\n\t\t\tWELL COME TO USE ATMcard system WITH US");
            printf("\n\t\t\tCreate PIN number for customer:");
            printf("\n\t\t\t...");
            scanf("%d", & pin);
            for (int k = 0; k < numberofcustomer; k++) {
              if (pin == cust[k].pin) {
                int z = 0;
                while (pin == cust[k].pin) {
                  printf("\nenter new PIN for customer the frist one is exist:");
                  scanf("%d", & pin);
                  system("clear");
                  z++;
                }
              }
            }
            cust[i].pin = pin;
            printf("\n Thankyou for using ATMcard with us!\n");
            break;
          } else {
            if (i == numberofcustomer - 1) {
              printf("\nCUSTOMER INFORMATION IS MIS-MATCH");
            }
          }
        }
      break;
      case 2:ATMcard();
      break;
      default:
      if(option<0 || option>2)
      {
      printf("\n invalid option\n");
      }
      }
      }while(option !=0);
        //break;
      } else {
        if (j == numberofemployer - 1) {
          printf("\nEMPLOYER INFORMATION IS MIS-MATCH");
        }
      }
    }
    break;
  case 3:
    ATMcard();
    break;
  case 2:
    Manual_system();
    break;
  default:
    if (choice < 1 || choice > 3) {
      printf("\n INVALID choice\n");
    }
  }

}
void CBEbirr() {
  /*function definition that explain some function of CBEbirr , as we write this project we can use PIN to access the ATM system and CBEbirr it means by the same PIN which we create when we add a customer to a member of banking system*/
  system("clear");
    char username[25], password[25];
      long int account_num, phone;
      int CBEpin;
  int option;
  do {
    printf("\n==============================");
    printf("\nDid you have a CBEbirr ?  ====");
    printf("\n1:Yes                     ====");
    printf("\n2:Enter 2 to register     ====");
    printf("\n3:to back                 ====");
    printf("\n==============================");
    printf("\n...");
    scanf("%d", & option);
    switch (option) {
    case 1:
      do {
        printf("\n\t\t\t=====welcome to CBE mobile banking==============");
        printf("\n\t\t\t=================================================");
        printf("\n\t\t\t=================================================");
        printf("\n\t\t\t====1:login                      ================");
        printf("\n\t\t\t====2:to back menu               ================");
        printf("\n\t\t\t=================================================");
        printf("\n\t\t\t=================================================");
        printf("\n\t\t\tselect one of the above options:");
        scanf("%d", & option);
        switch (option) {
        case 1:
          system("clear");
          login();
          break;
        case 2:
          CBEbirr();
          break;
        default:
          if (option < 1 || option > 2) {
            printf("\n invalid option\n");
          }
        }
      } while (1);
      break;
    case 2:
      printf("\nEnter username of employer:");
      scanf("%s", username);
      printf("\nEnter password of employer:");
      scanf("%s", password);
      for (int i = 0; i < numberofemployer; i++) {
        int uname = strcmp(username, emp[i].username);
        int pass = strcmp(password, emp[i].password);
        if (uname == 0 && pass == 0) {
        
       printf("\nWELL COME TO USING CBEbirr WITH US");  
       do{ 
      printf("\n 1 :CREATE CBEbirr ACCOUNT");
      printf("\n 2 :BACK");
      printf("\n 0 :exit");
      printf("\n ...");
      scanf("%d", &option);
      switch(option){
         case 1:
          printf("\nEnter customer account number:");
          scanf("%lu", & account_num);
          printf("\nEnter customer phone number:");
          scanf("%lu", & phone);
          for (int j = 0; j < numberofcustomer; j++) {
            if (account_num == cust[j].account_number && phone == cust[j].phone_number) {
              printf("\n create a PIN for customer:");
              scanf("%d", & CBEpin);
              for (int k = 0; k < numberofcustomer; k++) {
                if (CBEpin == cust[k].CBEpin) {
                  int z = 0;
                  while (CBEpin == cust[k].CBEpin) {
                    printf("\nenter new PIN for customer the frist one is exist:");
                    scanf("%d", & CBEpin);
                    system("clear");
                    z++;
                  }
                }
              }
              cust[j].CBEpin = CBEpin;
              printf("\n thankyou for using CBEbirr with us!\n");
              break;
            } else {
              if (j == numberofcustomer - 1) {
                printf("\nCUSTOMER INFORMATION NOT MATCH\n");
              }
            }
          }
         break;
         case 2: CBEbirr();
         break;
         default:
         if(option<0 || option>2){
         printf("\ninvalid option\n");
         }
          }
     }while(option !=0);
        } else {
          if (i == numberofemployer - 1) {
            printf("\nEMPLOYER INFORMATION NOT MATCH\n");
          }
        }
      }
      break;
    case 3:
      main();
      break;
    default:
      if (option < 1 || option > 3) {
        printf("\nINVALID option\n");
      }
    }
  } while (1);
}
void login() { //function definition used to login into some function of CBEbirr 
  system("clear");
  int option, pin;
  float user_amount = 0;
  long int account_number, phone_number;
  printf("\n please enter your PIN to login:");
  scanf("%d", & pin);
  for (int i = 0; i < numberofcustomer; i++) {
    if (pin == cust[i].CBEpin) {
      system("clear");
      do {
        printf("\n\t\t\t=================================================");
        printf("\n\t\t\t=================================================");
        printf("\n\t\t\t====welcome to CBE mobile banking      ==========");
        printf("\n\t\t\t====1:my accounts                      ==========");
        printf("\n\t\t\t====2:transfer to CBE account          ==========");
        printf("\n\t\t\t====3:top up airtime                   ==========");
        printf("\n\t\t\t====4:transfer to CBE birr wallet      ==========");
        printf("\n\t\t\t====0:to back menu                     ==========");
        printf("\n\t\t\t=================================================");
        printf("\n\t\t\t=================================================");
        printf("\n\t\t\tselect one of the above options:");
        scanf("%d", & option);
        switch (option) {
        case 1:
          printf("\n\t\t\t=================================================");
          printf("\nmy accounts");
          printf("\n1:youth S-ETB-%lu\n", cust[i].account_number);
          scanf("%d", & option);
          if (option == 1) {
            printf("\n%s %s %s", cust[i].fristname, cust[i].fathername, cust[i].lastname);
            printf("\nAvailable balance is ETB-%f", cust[i].amount);
            printf("\ntransactions");
          }
          break;
        case 2:
          printf("\n\t\t\t=================================================\n");
          printf("transfer to CBE account");
          printf("1:youth S-ETB-%lu\n", cust[i].account_number);
          scanf("%d", & option);
          if (option == 1) {
            system("clear");
            printf("\nRefine");
            printf("\nplease enter account number to transfer");
            scanf("%lu", & account_number);
            if (account_number == cust[i].account_number) {
              printf("\nyou can't transfer to your self\n");
              int m = 0;
              while (account_number != cust[i].account_number) {
                printf("\nplease enter account number to transfer");
                scanf("%lu", & account_number);
                m++;
              }
            }
            for (int j = 0; j < numberofcustomer; j++) {
              if (account_number == cust[j].account_number) {
                printf("\n you request transfer to:%s %s %s", cust[j].fristname, cust[j].fathername, cust[j].lastname);
                printf("\nenter amount to transfer:");
                scanf("%f", & cust[i].transfer);
                if (cust[i].transfer > cust[i].amount) {
                  printf("\n You have insufficient balance for this service\n");
                } else {
                  cust[i].amount -= cust[i].transfer;
                  cust[j].amount += cust[i].transfer;
                  printf("\nTRANSFERED SUCCESFULLY\n");

                }
              }
            }
          } else {
            printf("\n invalid input.");
          }

          break;
        case 3:

          printf("\n Buy Airtime");
          printf("\n1: Youth S-ETB-%lu:", cust[i].account_number);
          scanf("%d", & option);
          if (option == 1) {
            system("clear");
            printf("\n Youth S-ETB-%lu", cust[i].account_number);
            printf("\nRequest transfer from youth S-ETB-%lu", cust[i].account_number);
            printf("\n please enter recharged mobile number:");
            scanf("%lu", & phone_number);
            for (int j = 0; j < numberofcustomer; j++) {
              if (phone_number == cust[j].phone_number) {
                printf("\nConfirm request from: %s %s %s", cust[j].fristname, cust[j].fathername, cust[j].lastname);
                printf("\nRequest transfer from youth S-ETB-%lu", cust[i].account_number);
                printf("\nplease enter amount:");
                scanf("%f", & cust -> charge);
                if (cust -> charge < cust[i].amount) {
                  printf("\nConfirm request from: %s %s %s", cust[j].fristname, cust[j].fathername, cust[j].lastname);
                  printf("\nRequest transfer from youth S-ETB-%lu", cust[j].account_number);
                  printf("\nrecharged mob no:%lu", phone_number);
                  printf("\n please confirm:");
                  printf("\n1:yes");
                  printf("\n2:no\n");
                  scanf("%d", & option);

                  switch (option) {
                  case 1:
                    printf("\ncomplete");
                    printf("\nETB %f debited from %s %s %s-ETB-%lu for top up %lu.",
                      cust -> charge, cust[i].fristname, cust[i].fathername, cust[i].lastname, cust[i].account_number, cust[j].phone_number);
                    cust[i].amount -= cust -> charge;
                    printf("\n Dear customer your account");
                    printf("\n%lu has been debited with ETB %f.", cust[i].account_number, cust -> charge);
                    printf("\nyour current balance is ETB %f.", cust[i].amount);
                    printf("\nthank you for banking with CBE!\n");
                    break;
                  case 2:
                    printf("\n incomplete\n");
                    break;
                  default:
                    printf("\ninvalid option\n");
                  }
                } else {
                  printf("\n insufficient balance.\n");
                }
                break;
              } else {
                printf("\n invalid mobile number.\n");

              }
            }
          }
          break;
        case 4:
          printf("\n Transfer to CBEBirr Account");
          printf("\n1: Youth S-ETB-%lu:", cust[i].account_number);
          scanf("%d", & option);
          if (option == 1) {

            printf("\n Youth S-ETB-%lu", cust[i].account_number);
            printf("\nRequest transfer from youth S-ETB-%lu", cust[i].account_number);
            printf("\n please enter mobile number:");
            scanf("%lu", & phone_number);
            for (int j = 0; j < numberofcustomer; j++) {
              if (phone_number == cust[j].phone_number) {
                printf("\nYouth : %s %s %s", cust[j].fristname, cust[j].fathername, cust[j].lastname);
                printf("\nRequest transfer from youth S-ETB-%lu", cust[i].account_number);
                printf("\nplease enter amount:");
                scanf("%f", & cust -> charge);
                if (cust -> charge < 5) {
                  printf("\nAmount is less than minimum transaction amount.\n");
                  break;
                }
                if (cust -> charge < cust[j].amount) {
                  printf("\nYouth : %s %s %s ", cust[j].fristname, cust[j].fathername, cust[j].lastname);
                  printf("\nRequest transfer from youth S-ETB-%lu", cust[i].account_number);
                  printf("\nmobile number:%lu", phone_number);
                  printf("\n Amount:%f", cust -> charge);
                  printf("\n please confirm:");
                  printf("\n1:yes");
                  printf("\n2:no\n");
                  scanf("%d", & option);

                  switch (option) {
                  case 1:
                    printf("\ncomplete");
                    printf("\nETB %f debited from %s %s %s-ETB-%lu for top up %lu.",
                      cust -> charge, cust[i].fristname, cust[i].fathername, cust[i].lastname, cust[i].account_number, cust[j].phone_number);
                    cust[i].amount -= cust -> charge;
                    printf("\n Dear customer your account");
                    printf("\n%lu has been debited with ETB %f.", cust[i].account_number, cust -> charge);
                    printf("\nyour current balance is ETB %f.", cust[i].amount);
                    printf("\nthank you for banking with CBE!\n");
                    break;
                  case 2:

                    printf("\n incomplete\n");
                    break;
                  default:
                    printf("\ninvalid option\n");
                  }
                } else {
                  printf("\n insufficient balance.\n");
                }
              }
            }
          }
          break;
        default:
          if (option < 0 || option > 4) {
            printf("\n invalid option.");
          }
        }
      } while (option != 0);
      break;
    } else {
      if (i == numberofcustomer - 1) {
        printf("\ninvalid PIN\n");
      }
    }
  }

}
