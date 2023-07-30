/* 
    Developer Name    : Paruchuri Umesh Chandra
    University Name   : SR University
    University Email  : 2203a51579@sru.edu.in
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct EduPortal{

    // Personal Details :
        char StudentName[25];
        char FatherName[25];
        char MotherName[25];
        char MotherOcuupation[20];
        char FatherOccupation[20];
        char MotherNumber[11];
        char FatherNumber[11];
        char FamilyIncome[11]; 

    // University Details : 
        char EmailAddress[22];
        char PersonolMailAddress[30];
        char HallTicketNo[11];
        char Password[16];
        char Passwordx[16];
        char Passwordy[16];
        char Branch[8];
        char Degrree[8];
        char AdmissionCategory[10];
        char stay[10];

    // SSC Details : 
        char THallticketNo[15];
        char BoardOfStudy[10];
        char TPassType[10];
        char TMedium[10];
        char YearOfPass[5];
        char DOB[10];
        char PhyscicallyHandicapped[5];
        char SchoolName[25];
        char TMarks[4];
        char AdhaarNumber[12];

    // Intermediate Details :
        char IHallTicketNumber[15];
        char IMarks[4];
        char IPassType[10];
        char IYearOfPass[5];
        char Group[5];
        char IMedium[10];
        char CollegeName[25];  

    // CET Details :
        char CETType[10];
        char CETYear[5];
        char CETHallTicketNo[15];
        char CETRank[9];

    // Medical Details : 
        char BloodGroup[3];
        char IdentificationMarks1[50];
        char IdentificationMarks2[50];
}stux;

// Global Declarations Of Variables :
    char MailChecker[21];
    char PasswordChecker[21];
    int MailIndex = 0;
    int PasswordIndex = 0;
    int WrongPasswordCount = 0;
    int Retry = 0;

    // Security Questions : 
    char SQ1[] = "What Is Your GirlFriend's First Name ?";
    char SQ2[] = "What Is Your Pet's Name ?";
    char SQ3[] = "What Is Your Birth Place ?";
    char SQ4[] = "Where Did You Propose Your Girlfriend ?";
    char SQ5[] = "What Is Your Lucky Number ?";

void AdminLogIn(){
    char AdminPassword[] = "1413914";
    char AdminPasswordChecker[10];
    Admin : printf("Enter Admin Password :");
    gets(AdminPasswordChecker);
    fflush(stdin);
    if (strcmp(AdminPasswordChecker,AdminPassword) == 0 ){
        int Choice;
        AdminControls : printf("Press \n1 To Update Student Details \n2 To Change Student's Password\n3 To Exit\n");
        printf("\nPlease Enter Your Choice : ");
        scanf("%d",&Choice);
        fflush(stdin);
        printf("Enter Student's Hall Ticket Number : ");
        gets(stux.HallTicketNo);
        fflush(stdin);
        if(Choice == 1){
            UpdateStudentdetails();
            goto AdminControls;
        }
        else if (Choice == 2){
            ChangePassword();
            goto AdminControls;
        }
        else if (Choice == 3){
            goto End;
        }
        else{
            printf("\n\tYou Have Entered Incorrecct Choice \nPlease Enter Correcly\n");
            goto AdminControls;
        }
    }
    else{
        printf("Incorrect Admin Password ! Please Try Again");
        goto Admin;
    }
    End : return; 
}

void UpdateStudentAttendence(){
    printf("\n\n");
    char StudentProfileFileName[25];
    char Attendence[15] = "Attendence.txt";
    strcat(strcpy(StudentProfileFileName,stux.HallTicketNo),Attendence);
    FILE *UpdateFilePointer = fopen(StudentProfileFileName,"w+");
    if (UpdateFilePointer == NULL) {
        printf("\n\tProfile Can't Be Opened \n");
        printf("\n\tPlease Contact Administration Department InCase Of New Account\n");
        fclose(UpdateFilePointer);
        UpdateStudentdetails();
    }
    else{
        float Attendence;
        printf("Enter Attendence In Engineering Mathematics : ");
        scanf("%f",&Attendence);
        fprintf(UpdateFilePointer,"Engineering Mathematics                   %.2f %%\n",Attendence);
        printf("Enter Attendence In Applied Physics : ");
        scanf("%f",&Attendence);
        fprintf(UpdateFilePointer,"Applied Physics                           %.2f %%\n",Attendence);
        printf("Enter Attendence In Problem Solving In Programming : ");
        scanf("%f",&Attendence);
        fprintf(UpdateFilePointer,"Problem Solving In Programming            %.2f %%\n",Attendence);
        printf("Enter Attendence In English Language Enrichment : ");
        scanf("%f",&Attendence);
        fprintf(UpdateFilePointer,"English Language Enrichment               %.2f %%\n",Attendence);
        printf("Enter Attendence In Problem Solving In Programming Lab : ");
        scanf("%f",&Attendence);
        fprintf(UpdateFilePointer,"Problem Solving In Programming Lab        %.2f %%\n",Attendence);
        printf("Enter Attendence In Product Design Studio : ");
        scanf("%f",&Attendence);
        fprintf(UpdateFilePointer,"Product Design Studio                     %.2f %%\n",Attendence);
        printf("Enter Attendence In Advanced Programming Tools And Techniques Lab : ");
        scanf("%f",&Attendence);
        fprintf(UpdateFilePointer,"Advanced Programming Tools And Techniques %.2f %%\n",Attendence);
        printf("Enter Attendence In Engineering Physics Lab : ");
        scanf("%f",&Attendence);
        fprintf(UpdateFilePointer,"Engineering Physics Lab                   %.2f %%\n",Attendence);
        printf("\n\tDetails Updated Sucessfully\n");
    }
    fclose(UpdateFilePointer);
}

void UpdateStudentFeePayment(){
    char StudentFeePaymentFileName[25];
    char FeePayment[15] = "FeePayment.txt";
    char ch;
    strcat(strcpy(StudentFeePaymentFileName,stux.HallTicketNo),FeePayment);
    printf("\n\n");
    FILE *UpdateFeePaymentPointer = fopen(StudentFeePaymentFileName,"w+");
    if (UpdateFeePaymentPointer == NULL) {
        printf("\n\tFeePayment Can't Be Opened \n");
        printf("\n\tPlease Contact Administration Department InCase Of New Account\n");
        fclose(UpdateFeePaymentPointer);
        UpdateStudentdetails();
        return;
    }
    else{
        float SemFee,PaidFee;
        float Zero = 0.000000;
        printf("Enter Semester Fee : ");
        scanf("%f",&SemFee);
        fprintf(UpdateFeePaymentPointer,"Semester Fee : %.2f Rs\n",SemFee);
        printf("Enter Amount Paid : ");
        scanf("%f",&PaidFee);
        fprintf(UpdateFeePaymentPointer,"Amount Paid  : %.2f Rs\n",PaidFee);
        fprintf(UpdateFeePaymentPointer,"Due Fee      : %.2f Rs\n",(SemFee-PaidFee) >= 0 ? SemFee-PaidFee : Zero );  
        printf("\n\tDetails Updated Sucessfully\n");
    }
    fclose(UpdateFeePaymentPointer);
}

void UpdateStudentInternals(){
    char StudentInternalsFileName[25];
    char Internals[15] = "Internals.txt";
    strcat(strcpy(StudentInternalsFileName,stux.HallTicketNo),Internals);
    printf("\n\n");
    FILE *UpdateInternalsPointer = fopen(StudentInternalsFileName,"w+");
    if (UpdateInternalsPointer == NULL) {
        printf("\n\tInternals Can't Be Opened \n");
        printf("\n\tPlease Contact Administration Department InCase Of New Account\n");
        fclose(UpdateInternalsPointer);
        UpdateStudentdetails();
    }
    else{
        float int1,int2;
        printf("Enter Mid 1 Engineering Mathematics Marks : ");
        scanf("%f",&int1);
        printf("Enter Mid 2 Engineering Mathematics Marks : ");
        scanf("%f",&int2);
        fprintf(UpdateInternalsPointer,"Engineering Mathematics                     %.2f\n", (int1>int2) ? ((int1*0.75+int2*0.25)) : ((int2*0.75+int1*0.25)));
        printf("Enter Mid 1 Applied Physics Marks : ");
        scanf("%f",&int1);
        printf("Enter Mid 2 Applied Physics Marks : ");
        scanf("%f",&int2);
        fprintf(UpdateInternalsPointer,"Applied Physics                             %.2f\n", (int1>int2) ? ((int1*0.75+int2*0.25)) : ((int2*0.75+int1*0.25)));
        printf("Enter Mid 1 Problem Solving In Programming Marks : ");
        scanf("%f",&int1);
        printf("Enter Mid 2 Problem Solving In Programming Marks : ");
        scanf("%f",&int2);
        fprintf(UpdateInternalsPointer,"Problem Solving In Programming              %.2f\n", (int1>int2) ? ((int1*0.75+int2*0.25)) : ((int2*0.75+int1*0.25)));
        printf("Enter Mid 1 English Language Enrichment Marks : ");
        scanf("%f",&int1);
        printf("Enter Mid 2 English Language Enrichment : ");
        scanf("%f",&int2);
        fprintf(UpdateInternalsPointer,"English Language Enrichment                 %.2f\n", (int1>int2) ? ((int1*0.75+int2*0.25)) : ((int2*0.75+int1*0.25)));
        printf("Enter Mid 1 Problem Solving In Programming Lab Marks : ");
        scanf("%f",&int1);
        printf("Enter Mid 2 Problem Solving In Programming Lab Marks : ");
        scanf("%f",&int2);
        fprintf(UpdateInternalsPointer,"Problem Solving In Programming Lab          %.2f\n", (int1>int2) ? ((int1*0.75+int2*0.25)) : ((int2*0.75+int1*0.25)));
        printf("Enter Mid 1 Product Design Studio Marks : ");
        scanf("%f",&int1);
        printf("Enter Mid 2 Product Design Studio Marks : ");
        scanf("%f",&int2);
        fprintf(UpdateInternalsPointer,"Product Design Studio                       %.2f\n", (int1>int2) ? ((int1*0.75+int2*0.25)) : ((int2*0.75+int1*0.25)));
        printf("Enter Mid 1 Advanced Programming Tools And Techniques Marks : ");
        scanf("%f",&int1);
        printf("Enter Mid 2 Advanced Programming Tools And Techniques Marks : ");
        scanf("%f",&int2);
        fprintf(UpdateInternalsPointer,"Advanced Programming Tools And Techniques   %.2f\n", (int1>int2) ? ((int1*0.75+int2*0.25)) : ((int2*0.75+int1*0.25)));
        printf("Enter Mid 1 Engineering Physics Lab Marks : ");
        scanf("%f",&int1);
        printf("Enter Mid 2 Engineering Physics Lab Marks : ");
        scanf("%f",&int2);
        fprintf(UpdateInternalsPointer,"Engineering Physics Lab                     %.2f\n", (int1>int2) ? ((int1*0.75+int2*0.25)) : ((int2*0.75+int1*0.25)));
        printf("\n\tDetails Updated Sucessfully !\n");
    }
    fclose(UpdateInternalsPointer);
}

void UpdateStudentdetails(){
    int Choice;
    printf("\nWhat Do You Want To Update \n 1.Attendence \n 2.FeePayment \n 3.Internals\n");
    UpdateOptions : printf("\nPlease Enter Your Choice : ");
    scanf("%d",&Choice);
    fflush(stdin);
    switch (Choice)
    {
    case 1:
        UpdateStudentAttendence();
        break;
    case 2:
        UpdateStudentFeePayment();
        break;
    case 3:
        UpdateStudentInternals();
        break;
    default: 
        printf("\n\tYou Have Selected Wrong Choice Please Enter Correcly !\n");
        goto UpdateOptions;
        break;
    }
}

int SubstringCheck(char* s1, char* s2){
    int M = strlen(s1);
    int N = strlen(s2);
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;
        if (j == M)
        return 1;
    }
    return 0;
}

void CalcSgpa(){ 
    // Credits : 
    int CDE_C = 4;
    int ELE_C = 2;
    int EP_C = 3;
    int SSD_C = 3;
    int PDS_C = 3;
    int EPL_C = 1;
    int BEEE_C = 3;
    int IP_C = 2;
    int IPL_C = 1;
    int PTT_C = 2;
    int EC_C = 3;
    int GDM_C = 2;
    int ECL_C = 1;
    float GPA = 0;
    char Branch[5];
    char Section[4];
    int CDE_GP, EP_GP, IP_GP, ELE_GP, EC_GP, BEEE_GP;
    int PDS_GP, IPL_GP, PTT_GP, EPL_GP, GDM_GP, ECL_GP, SSD_GP;
    printf("\n\t\t\t-------------------------------------SGPA Calculator-------------------------------------\n");
    printf("Existing Branches : \n CSE \n ECE \n EEE \n Mechanical \n Civil \n\n Enter Your Branch (Use Upper Case) : ");
    gets(Branch);
    fflush(stdin);
    printf("\nExisting Sections :\n\n A1 B1 C1 D1 E1 F1 G1 H1 I1 J1 K1 \n A2 B2 C2 D2 E2 F2 G2 H2 I2 J2 K2 \n\n Enter Your Section : ");
    gets(Section);
    fflush(stdin);
    printf("\n\n");
    if (strcmp(Branch,"CSE") == 0 && SubstringCheck("1",Section)){
        printf("\nTheory:\n");
        printf("Enter Grade in C&DE: ");
        scanf("%d", &CDE_GP);
        printf("Enter Grade in EP: ");
        scanf("%d", &EP_GP);
        printf("Enter Grade in IP: ");
        scanf("%d", &IP_GP);
        printf("Enter Grade in ELE: ");
        scanf("%d", &ELE_GP);
        printf("\nLabs:\n");
        printf("Enter Grade in PDS: ");
        scanf("%d", &PDS_GP);
        printf("Enter Grade in IPL: ");
        scanf("%d", &IPL_GP);
        printf("Enter Grade in PTT: ");
        scanf("%d", &PTT_GP);
        printf("Enter Grade in EPL: ");
        scanf("%d", &EPL_GP);
        GPA = (float)(CDE_C * CDE_GP + EP_C * EP_GP + IP_C * IP_GP + ELE_C * ELE_GP + PDS_C * PDS_GP + EPL_C * EPL_GP + IPL_C * IPL_GP + PTT_C * PTT_GP) / (CDE_C + EP_C + IP_C + ELE_C + PDS_C + EPL_C + IPL_C + PTT_C); 
    }

    else if ((strcmp(Branch,"ECE") == 0 || strcmp(Branch,"EEE") == 0) && SubstringCheck("1",Section)){
        printf("\nTheory:\n");
        printf("Enter Grade in C&DE: ");
        scanf("%d", &CDE_GP);
        printf("Enter Grade in EP: ");
        scanf("%d", &EP_GP);
        printf("Enter Grade in IP: ");
        scanf("%d", &IP_GP);
        printf("Enter Grade in ELE: ");
        scanf("%d", &ELE_GP);
        printf("\nLabs:\n");
        printf("Enter Grade in PDS: ");
        scanf("%d", &PDS_GP);
        printf("Enter Grade in IPL: ");
        scanf("%d", &IPL_GP);
        printf("Enter Grade in GDM: ");
        scanf("%d", &GDM_GP);
        printf("Enter Grade in EPL: ");
        scanf("%d", &EPL_GP);
        GPA = (float)((CDE_C*CDE_GP)+(EP_C*EP_GP)+(IP_C*IP_GP)+(ELE_C*ELE_GP)+(PDS_C*PDS_GP)+(EPL_C*EPL_GP)+(IPL_C*IPL_GP)+(GDM_C*GDM_GP))/((CDE_C)+(EP_C)+(IP_C)+(ELE_C)+(PDS_C)+(EPL_C)+(IPL_C)+(GDM_C));
    }

    else if ((strcmp("Mechanical",Branch) == 0 || strcmp("Civil",Branch) == 0) && SubstringCheck("1",Section)){
        printf("\nTheory:\n");
        printf("Enter Grade in C&DE: ");
        scanf("%d", &CDE_GP);
        printf("Enter Grade in EP: ");
        scanf("%d", &EP_GP);
        printf("Enter Grade In EC : ");
        scanf("%d", &EC_GP); 
        printf("\nLabs:\n");
        printf("Enter Grade in PDS: ");
        scanf("%d", &PDS_GP);
        printf("Enter Grade in GDM: ");
        scanf("%d", &GDM_GP);
        printf("Enter Grade In ECL : ");
        scanf("%d", &ECL_GP);
        GPA = (float)((CDE_C*CDE_GP)+(EP_C*EP_GP)+(EC_C*EC_GP)+(PDS_C*PDS_GP)+(ECL_C*ECL_GP)+(GDM_C*GDM_GP))/((CDE_C)+(EP_C)+(EC_C)+(PDS_C)+(ECL_C)+(GDM_C));
    }

    else if (strcmp(Branch,"CSE") == 0 && SubstringCheck("2",Section)){
        printf("\nTheory:\n");
        printf("Enter Grade in C&DE: ");
        scanf("%d", &CDE_GP);
        printf("Enter Grade in EP: ");
        scanf("%d", &EP_GP);
        printf("Enter Grade in IP: ");
        scanf("%d", &IP_GP);
        printf("Enter Grade in BEEE: ");
        scanf("%d", &BEEE_GP);
        printf("\nLabs:\n");
        printf("Enter Grade in SSD: ");
        scanf("%d", &SSD_GP);
        printf("Enter Grade in IPL: ");
        scanf("%d", &IPL_GP);
        printf("Enter Grade in PTT: ");
        scanf("%d", &PTT_GP);
        printf("Enter Grade in EPL: ");
        scanf("%d", &EPL_GP);
        GPA = (float)((CDE_C*CDE_GP)+(EP_C*EP_GP)+(IP_C*IP_GP)+(BEEE_C*BEEE_GP)+(SSD_C*SSD_GP)+(EPL_C*EPL_GP)+(IPL_C*IPL_GP)+(PTT_C*PTT_GP))/((CDE_C)+(EP_C)+(IP_C)+(BEEE_C)+(SSD_C)+(EPL_C)+(IPL_C)+(PTT_C));
    }

    else if ((strcmp(Branch,"ECE") == 0 || strcmp(Branch,"EEE") == 0) && SubstringCheck("2",Section)){
        printf("\nTheory:\n");
        printf("Enter Grade in C&DE: ");
        scanf("%d", &CDE_GP);
        printf("Enter Grade in EP: ");
        scanf("%d", &EP_GP);
        printf("Enter Grade in IP: ");
        scanf("%d", &IP_GP);
        printf("Enter Grade in BEEE: ");
        scanf("%d", &BEEE_GP);
        printf("\nLabs:\n");
        printf("Enter Grade in SSD: ");
        scanf("%d", &SSD_GP);
        printf("Enter Grade in IPL: ");
        scanf("%d", &IPL_GP);
        printf("Enter Grade in EPL: ");
        scanf("%d", &EPL_GP);
        printf("Enter Grade in GDM: ");
        scanf("%d", &GDM_GP);
        GPA = (float)((CDE_C*CDE_GP)+(EP_C*EP_GP)+(IP_C*IP_GP)+(BEEE_C*BEEE_GP)+(SSD_C*SSD_GP)+(EPL_C*EPL_GP)+(IPL_C*IPL_GP)+(GDM_C*GDM_GP))/((CDE_C)+(EP_C)+(IP_C)+(BEEE_C)+(SSD_C)+(EPL_C)+(IPL_C)+(GDM_C));
    }

    else if ((strcmp("Mechanical",Branch) == 0 || strcmp("Civil",Branch) == 0) && SubstringCheck("2",Section)){
        printf("\nTheory:\n");
        printf("Enter Grade in C&DE: ");
        scanf("%d", &CDE_GP);
        printf("Enter Grade in EP: ");
        scanf("%d", &EP_GP);
        printf("Enter Grade In EC : ");
        scanf("%d", &EC_GP); 
        printf("\nLabs:\n");
        printf("Enter Grade in SSD: ");
        scanf("%d", &SSD_GP);
        printf("Enter Grade in EPL: ");
        scanf("%d", &EPL_GP);
        printf("Enter Grade in GDM: ");
        scanf("%d", &GDM_GP);
        printf("Enter Grade In ECL : ");
        scanf("%d", &ECL_GP);
        GPA = (float)((CDE_C*CDE_GP)+(EP_C*EP_GP)+(EC_C*EC_GP)+(SSD_C*SSD_GP)+(EPL_C*EPL_GP)+(ECL_C*ECL_GP)+(GDM_C*GDM_GP))/((CDE_C)+(EP_C)+(EC_C)+(SSD_C)+(EPL_C)+(ECL_C)+(GDM_C));
    }

    else{
        printf("\n\tInvalid Section Name Or Branch Name Please Enter It Correclty\n\n\n");
        LogInOptions();
    }

    if(GPA>10){
        printf("\n\tYou Have Entered Invalid Inputs For Grade Points Please Enter Correctly\n\n\n");
        LogInOptions();
    }
    else{
        printf("\n\tYour SGPA Is : %.3f\n",GPA) ;  
        printf("\n\t\t\t\t\t\t\tThank You !\n\n\n");
        LogInOptions();
    }
}

void LogInOptions(){
    int x;
    printf("Press \n1 To Log In To Existing Account\n2 To Create New Account\n3 To Calculate SGPA\n4 For Admin Login\n");
    printf("\nEnter Your Choice : ");
    scanf("%d",&x);
    fflush(stdin);
    if ( x == 1 )
        LogIn();
    else if ( x == 2 )
        CreateNewAcccount();                                          
    else if ( x == 3 )
        CalcSgpa();                                   
    else if ( x == 4 )
        AdminLogIn();                                          
    else{
        printf("\n\tYou Have Choosen Invalid Option\n\nPlease Select Again :\n");
        LogInOptions();
    }
}

int CheckCredentials( char HallTicketNo[], char Password[]) {
    char HallTicketChecker[22];
    char PasswordChecker[15];
    FILE* CheckCredentialsFilePointer;
    CheckCredentialsFilePointer = fopen("Emails_Passwords.txt", "r");
    if (CheckCredentialsFilePointer == NULL) {
        printf("\n\tError Checking Credentials.\n");
        return 0;
    }
    while (fscanf(CheckCredentialsFilePointer, "%s %s", HallTicketChecker, PasswordChecker) != EOF) {
        if (strcmp(HallTicketNo, HallTicketChecker) == 0 && strcmp(Password, PasswordChecker) == 0) {
            fclose(CheckCredentialsFilePointer); 
            return 1; 
        }
    }
    fclose(CheckCredentialsFilePointer); 
    return 0;
}

int CheckIfAccountExists(char HallTicketNo[]){
    char HallTicketChecker[22];
    FILE* CheckAccountExistsPointer;
    CheckAccountExistsPointer = fopen("Emails_Passwords.txt", "r");
    if (CheckAccountExistsPointer == NULL) {
        printf("\n\tError Checking If Account Exists.\n");
        return 0;
    }
    while (fscanf(CheckAccountExistsPointer, "%s", HallTicketChecker) != EOF) {
        if (strcmp(HallTicketNo, HallTicketChecker) == 0 ) {
            fclose(CheckAccountExistsPointer); 
            return 1; 
        }
    }
    fclose(CheckAccountExistsPointer); 
    return 0;
}

void LogIn(){
    printf("\nEnter Your University Hall Ticket Number : ");
    gets(stux.HallTicketNo);
    fflush(stdin);
    printf("Enter Your Password : ");
    gets(stux.Password);
    fflush(stdin);
    if (CheckCredentials(stux.HallTicketNo,stux.Password)){
        printf("\n\n\tLog In Sucessfull\n\n");
        SelectChoice();
    }
    else{
        if(WrongPasswordCount >= 2){
            int CH;
            printf("\nPress \n1.If You Forgot Your Password\n2.To Log In\n");
            EnteraChoice :printf("\nEnter Your Choice : ");
            scanf("%d",&CH);
            printf("\n");
            if(CH == 1)
                ResetPassword(stux.HallTicketNo);
            else if (CH == 2)
                LogIn();
            else {
                printf("\n\tYou Have Entered Wrong Choice ! Pleasse Re-Enter It Correctly !\n");
                goto EnteraChoice;
            }
        }
        else{
            printf("\n\tIncorrect University Hall Ticket Number Or Password\n");
            printf("\n\tTry Logging In Again\n\n");
            WrongPasswordCount++;
            LogIn();
        }
    }
}

void CreateNewAcccount(){
    int Ch;
    FILE *CreateNewAcc;
    FILE *AddSecurityQuestionsPointer;
    FILE *AddSecurityAnswersPointer;
    CreateNewAcc = fopen("Emails_Passwords.txt","a+");
    AddSecurityQuestionsPointer = fopen("Security_Questions.txt","a+");
    AddSecurityAnswersPointer = fopen("Security_Answers.txt","a+");
    printf("\nEnter Your University Hall Ticket Number : ");
    gets(stux.HallTicketNo);
    fflush(stdin);
    if (CheckIfAccountExists(stux.HallTicketNo)){
        printf("\n\tAn Account Exists With Hall Ticket Number %s !\n",stux.HallTicketNo);
        ExistsChoices : printf("Press \n 1 To Log In\n 2 If You Dont Remember Your Password\n 3 To Start Again\n");
        printf("\nSelect Your Choice : ");
        scanf("%d",&Ch);
        fflush(stdin);
        if (Ch == 1){
            LogIn();
        }
        else if (Ch == 2){
            ResetPassword(stux.HallTicketNo);
        }
        else if (Ch == 3){
            main();
        }
        else{
            printf("\n\tYour Have Entered Wrong Choice Please Enter It Again !\n");
            goto ExistsChoices;
        }
    }
    else{
    fprintf(CreateNewAcc,"\n%s ",stux.HallTicketNo);
    ReEnterPassword : printf("Enter Password : ");
    gets(stux.Passwordx);
    fflush(stdin);
    printf("Re-Enter Password : ");
    gets(stux.Passwordy);
    fflush(stdin);
    if(strcmp(stux.Passwordx,stux.Passwordy) == 0){
        strcpy(stux.Password,stux.Passwordx);
        fprintf(CreateNewAcc,"%s",stux.Password);
    }
    else{
        printf("\n\tPasswords Donot Match !!\n");
        goto ReEnterPassword;
    }
    fclose(CreateNewAcc);
    printf("\n\nSelect A Security Question : \n");
    int SQNumber = SelectSecurityQuestion();
    char SQChoice[7];
    char SecurityAns[25];
    switch (SQNumber){
    case 1:
        strcpy(SQChoice,"One");
        break;
    case 2:
        strcpy(SQChoice,"Two");
        break; 
    case 3:
        strcpy(SQChoice,"Three");
        break; 
    case 4:
        strcpy(SQChoice,"Four");
        break;
    case 5:
        strcpy(SQChoice,"Five");
        break;
    }
    printf("\nEnter Answer To The Security Question Selected (In One Word) : ");
    gets(SecurityAns);
    fflush(stdin);
    fprintf(AddSecurityQuestionsPointer, "\n%s %s", stux.HallTicketNo, SQChoice);
    fprintf(AddSecurityAnswersPointer, "\n%s %s", stux.HallTicketNo, SecurityAns);
    fclose(AddSecurityAnswersPointer);
    fclose(AddSecurityQuestionsPointer);
    FillDetails();
    }
}

void FillDetails(){
    printf(" \n\t\tNote : Details Once Given Cannot Be Changed By Student.\n\n");
    printf(" \t\t       Details Can Only Be Changed By Admin.\n\n");
    printf(" \t\tPlease Fill In Details Carefully : \n\n");
    printf("\nPersonal Details : \n");
    printf(" Name (As Per SSC): ");
    gets(stux.StudentName);
    fflush(stdin);
    printf(" Personal Mail Address : ");
    gets(stux.PersonolMailAddress);
    fflush(stdin);
    printf(" Father Name : ");
    gets(stux.FatherName);
    fflush(stdin);
    printf(" Mother Name : ");
    gets(stux.MotherName);
    fflush(stdin);
    printf(" Father's Mobile Number : ");
    gets(stux.FatherNumber);
    fflush(stdin);
    printf(" Mother's Mobile Number : ");
    gets(stux.MotherNumber);
    fflush(stdin);
    printf(" Father's Occupation : ");
    gets(stux.FatherOccupation);
    fflush(stdin);
    printf(" Mothers Occupation : ");
    gets(stux.FatherOccupation);
    fflush(stdin);
    printf(" Annual Income : ");
    gets(stux.FamilyIncome);
    fflush(stdin);
    printf(" Are You Physically Handicapped (Yes/No) : ");
    gets(stux.PhyscicallyHandicapped);
    fflush(stdin);
    printf("\nUniversity Details : \n");
    printf(" Degree : ");
    gets(stux.Degrree);
    fflush(stdin);
    printf(" Branch : ");
    gets(stux.Branch);
    fflush(stdin);
    printf(" Admission Category (Convener/Management) : ");
    gets(stux.AdmissionCategory);
    fflush(stdin);
    printf(" Your Stay (Hostel/Home) : ");
    gets(stux.stay);
    fflush(stdin);
    printf("\nSSC Details : \n");
    printf(" SSC Hall Ticket Number : ");
    gets(stux.THallticketNo);
    fflush(stdin);
    printf(" Marks / Grade Obtained In Class 10 : ");
    gets(stux.TMarks);
    fflush(stdin);
    printf(" Year Of Pass Of 10th : ");
    gets(stux.YearOfPass);
    fflush(stdin);
    printf(" Board Of Study (SSC/CBSE/ICSE) : ");
    gets(stux.BoardOfStudy);
    fflush(stdin);
    printf(" Pass Type (Regular/Supplementary) : ");
    gets(stux.TPassType);
    fflush(stdin);
    printf(" Medium Of Education : ");
    gets(stux.TMedium);
    fflush(stdin);
    printf(" School Name : ");
    gets(stux.SchoolName);
    fflush(stdin);
    printf(" Date Of Birth : ");
    gets(stux.DOB);
    fflush(stdin);
    printf(" Adhaar Number : ");
    gets(stux.AdhaarNumber);
    fflush(stdin);
    printf("\nIntermediate Details : \n");
    printf(" Intermediate HallTicket Number : ");
    gets(stux.IHallTicketNumber);
    fflush(stdin);
    printf(" College Name : ");
    gets(stux.CollegeName);
    fflush(stdin);
    printf(" Intermediate Group : ");
    gets(stux.Group);
    fflush(stdin);
    printf(" Medium Of Intruction : ");
    gets(stux.IMedium);
    fflush(stdin);
    printf(" Intermediate Marks : ");
    gets(stux.IMarks);
    fflush(stdin);
    printf(" Year Of Pass Of Intermediate : ");
    gets(stux.IYearOfPass);
    fflush(stdin);
    printf(" Pass Type (Regular/Supplementary) : ");
    gets(stux.IPassType);
    fflush(stdin);
    printf("\nCET Details\n");
    printf(" CET Type (EAMCET/ECET/ICET/PGCET/NONE) : ");
    gets(stux.CETType);
    fflush(stdin);
    printf(" CET Hall Ticket Number : ");
    gets(stux.CETHallTicketNo);
    fflush(stdin);
    printf(" CET Year : ");
    gets(stux.CETYear);
    fflush(stdin);
    printf(" CET Rank : ");
    gets(stux.CETRank);
    fflush(stdin);
    printf("\nMedical Details : \n");
    printf(" Blood Group : ");
    gets(stux.BloodGroup);
    fflush(stdin);
    printf(" Identification Marks 1 : ");
    gets(stux.IdentificationMarks1);
    fflush(stdin);
    printf(" Identification Marks 2 : ");
    gets(stux.IdentificationMarks2);
    fflush(stdin);
    printf("\n\tFor Updates Regarding Internals/Attendence/Fee Payment Contact Administration Department\n\n");
    printf("Saving .........................\n");
    SaveDetailsToFile();    
}

void SaveDetailsToFile(){
    char StudentProfileFileName[25];
    char Profile[15] = "Profile.txt";
    strcat(strcpy(StudentProfileFileName,stux.HallTicketNo),Profile);
    FILE *SaveDetailsPointer = fopen(StudentProfileFileName,"w+");
    if (SaveDetailsPointer == NULL) {
        printf("\n\tError Saving Contact Administration Department ! Trying Again !\n\n\n\n");
        if( Retry >= 5 ){
            printf("\n\tError Saving Contact Administration Department. \n\n\n\n");
            LogIn();
        }
        else{   
            Retry++;
            SaveDetailsToFile();
        }
    }
    else{
        fprintf(SaveDetailsPointer,"University Details : \n");
        fprintf(SaveDetailsPointer," \tName (As Per SSC) : %s\n ",stux.StudentName);
        fprintf(SaveDetailsPointer," \tHall Ticket Number : %s\n",stux.HallTicketNo);
        fprintf(SaveDetailsPointer," \tPersonal Mail Address : %s\n",stux.PersonolMailAddress);
        fprintf(SaveDetailsPointer," \tDate Of Birth : %s\n",stux.DOB);
        fprintf(SaveDetailsPointer," \tAdhaar Number : %s\n",stux.AdhaarNumber);
        fprintf(SaveDetailsPointer," \tDegree : %s\n",stux.Degrree);
        fprintf(SaveDetailsPointer," \tBranch : %s\n",stux.Branch);
        fprintf(SaveDetailsPointer," \tAdmission Category (Convener/Management) : %s\n",stux.AdmissionCategory);
        fprintf(SaveDetailsPointer," \tYour Stay (Hostel/Home) : %s\n",stux.stay);
        fprintf(SaveDetailsPointer," \tFather Name : %s\n",stux.FatherName);
        fprintf(SaveDetailsPointer," \tMother Name : %s\n",stux.MotherName);
        fprintf(SaveDetailsPointer," \tFather's Mobile Number : %s\n",stux.FatherNumber);
        fprintf(SaveDetailsPointer," \tMother's Mobile Number : %s\n",stux.MotherNumber);
        fprintf(SaveDetailsPointer," \tFather's Occupation : %s\n",stux.FatherOccupation);
        fprintf(SaveDetailsPointer," \tMothers Occupation : %s\n",stux.FatherOccupation);
        fprintf(SaveDetailsPointer," \tAnnual Income : %s\n",stux.FamilyIncome);
        fprintf(SaveDetailsPointer," \tPhysically Handicapped (Yes/No) : %s\n",stux.PhyscicallyHandicapped);
        fprintf(SaveDetailsPointer,"\nSSC Details : \n");
        fprintf(SaveDetailsPointer," \tSSC Hall Ticket Number : %s\n",stux.THallticketNo);
        fprintf(SaveDetailsPointer," \tMarks / Grade Obtained In Class 10 : %s\n",stux.TMarks);
        fprintf(SaveDetailsPointer," \tYear Of Pass Of 10th : %s\n",stux.YearOfPass);
        fprintf(SaveDetailsPointer," \tBoard Of Study (SSC/CBSE/ICSE) : %s\n",stux.BoardOfStudy);
        fprintf(SaveDetailsPointer," \tPass Type (Regular/Supplementary) : %s\n",stux.TPassType);
        fprintf(SaveDetailsPointer," \tMedium Of Education : %s\n",stux.TMedium);
        fprintf(SaveDetailsPointer," \tSchool Name : %s\n",stux.SchoolName);
        fprintf(SaveDetailsPointer,"\nIntermediate Details : \n");
        fprintf(SaveDetailsPointer," \tIntermediate HallTicket Number : %s\n",stux.IHallTicketNumber);
        fprintf(SaveDetailsPointer," \tCollege Name : %s\n",stux.CollegeName);
        fprintf(SaveDetailsPointer," \tIntermediate Group : %s\n",stux.Group);
        fprintf(SaveDetailsPointer," \tMedium Of Intruction : %s\n",stux.IMedium);
        fprintf(SaveDetailsPointer," \tIntermediate Marks : %s\n",stux.IMarks);
        fprintf(SaveDetailsPointer," \tYear Of Pass Of Intermediate : %s\n",stux.IYearOfPass);
        fprintf(SaveDetailsPointer," \tPass Type (Regular/Supplementary) : %s\n",stux.IPassType);
        fprintf(SaveDetailsPointer,"\nCET Details : \n");
        fprintf(SaveDetailsPointer," \tCET Type (EAMCET/ECET/ICET/PGCET/NONE) : %s\n",stux.CETType);
        fprintf(SaveDetailsPointer," \tCET Hall Ticket Number : %s\n",stux.CETHallTicketNo);
        fprintf(SaveDetailsPointer," \tCET Year : %s\n",stux.CETYear);
        fprintf(SaveDetailsPointer," \tCET Rank : %s\n",stux.CETRank);
        fprintf(SaveDetailsPointer,"\nMedical Details : \n");
        fprintf(SaveDetailsPointer," \tBlood Group : %s\n",stux.BloodGroup);
        fprintf(SaveDetailsPointer," \tIdentification Marks 1 : %s\n",stux.IdentificationMarks1);
        fprintf(SaveDetailsPointer," \tIdentification Marks 2 : %s\n",stux.IdentificationMarks2);
        fclose(SaveDetailsPointer);
        printf("\n\n\t\tSuccessfully Saved. \n\n");
        printf("\n\tNow Please Log In\n");
        LogIn();
    }
}  

void Profile(){
    printf("\n\nProfile : \n\n");
    char ch;
    char StudentProfileFileName[25];
    char Profile[15] = "Profile.txt";
    strcat(strcpy(StudentProfileFileName,stux.HallTicketNo),Profile);
    FILE *ViewFilePointer = fopen(StudentProfileFileName,"r");
    if (ViewFilePointer == NULL) {
        printf("\n\tProfile Can't Be Opened \n");
        printf("\n\tPlease Contact Administration Department InCase Of New Account\n");
        fclose(ViewFilePointer);
        SelectChoice();
        return;
    }
    else{
        do {
            ch = fgetc(ViewFilePointer);
            printf("%c", ch);
        } while (ch != EOF);
    }
    fclose(ViewFilePointer);
    SelectChoice();
}   

void Attendence(){
    char StudentAttendenceFileName[25];
    char Attendence[15] = "Attendence.txt";
    char ch;
    strcat(strcpy(StudentAttendenceFileName,stux.HallTicketNo),Attendence);
    printf("\n\nAttendence : \n\n");
    FILE *ViewAttendencePointer = fopen(StudentAttendenceFileName,"r");
    if (ViewAttendencePointer == NULL) {
        printf("\n\tAttendence Can't Be Opened \n");
        printf("\n\tPlease Contact Administration Department InCase Of New Account\n");
        fclose(ViewAttendencePointer);
        SelectChoice();
        return;
    }
    else{
        do {
            ch = fgetc(ViewAttendencePointer);
            printf("%c", ch);
        } while (ch != EOF);
    }
    printf("\n\n");
    fclose(ViewAttendencePointer);
    SelectChoice();
}

void FeePayment(){
    char StudentFeePaymentFileName[25];
    char FeePayment[15] = "FeePayment.txt";
    char ch;
    strcat(strcpy(StudentFeePaymentFileName,stux.HallTicketNo),FeePayment);
    printf("\n\nFee Payment : \n\n");
    FILE *ViewFeePaymentPointer = fopen(StudentFeePaymentFileName,"r");
    if (ViewFeePaymentPointer == NULL) {
        printf("\n\tFeePayment Can't Be Opened \n");
        printf("\n\tPlease Contact Administration Department InCase Of New Account\n");
        fclose(ViewFeePaymentPointer);
        SelectChoice();
        return;
    }
    else{
        do {
            ch = fgetc(ViewFeePaymentPointer);
            printf("%c", ch);
        } while (ch != EOF);
    }
    fclose(ViewFeePaymentPointer);
    SelectChoice();
}

void Internals(){
    char StudentInternalsFileName[25];
    char Internals[15] = "Internals.txt";
    char ch;
    strcat(strcpy(StudentInternalsFileName,stux.HallTicketNo),Internals);
    printf("\n\nInternal Marks : \n\n");
    FILE *ViewInternalsPointer = fopen(StudentInternalsFileName,"r");
    if (ViewInternalsPointer == NULL) {
        printf("\n\tInternals Can't Be Opened \n");
        printf("\n\tPlease Contact Administration Department InCase Of New Account\n");
        fclose(ViewInternalsPointer);
        SelectChoice();
    }
    else{
        do{
            ch = fgetc(ViewInternalsPointer);
            printf("%c", ch);
        }while (ch != EOF);
    }
    fclose(ViewInternalsPointer);
    SelectChoice();
}
    
void Grievence(){
    char StudentGrievenceFileName[25];
    char Grievence[15] = "Grievence.txt";
    strcat(strcpy(StudentGrievenceFileName,stux.HallTicketNo),Grievence);
    char Grievencee[250];
    printf("Enter Grievence  : ");
    gets(Grievencee);
    FILE *GrievencePointer = fopen(StudentGrievenceFileName,"w+");
    if (GrievencePointer == NULL){
        printf("\n\tGrievence Cannot Be Added !");
        fclose(GrievencePointer);
        SelectChoice();
    }
    else{
        fprintf(GrievencePointer,"%s Grievence : ",stux.HallTicketNo);
        fprintf(GrievencePointer,"%s",Grievencee);
        printf("\n\tGrievence Added Sucessfully, It Will Be Addressed Soon.\n");
        SelectChoice();
    }
    fclose(GrievencePointer);
}

int SelectSecurityQuestion(){
    int ch;
    printf("\n\t1.%s\n",SQ1);
    printf("\t2.%s\n",SQ2);
    printf("\t3.%s\n",SQ3);
    printf("\t4.%s\n",SQ4);
    printf("\t5.%s\n\n",SQ5);
    SelectSQ : printf("\nSelect Your Security Question : ");
    scanf("%d",&ch);
    fflush(stdin);
    if( ch >=1 && ch <= 5 ){
        return ch;
    }
    else{
        printf("\n\tYou Have Entered Wrong Choice Please Enter It Correctly\n");
        goto SelectSQ;
    }
}

int CheckSecurityQuestion (char HallTicketNo[], char SQ[]){
    char SQChecker[10];
    char HallTicketChecker[15];
    FILE *SecurityQuestionsPointer = fopen("Security_Questions.txt","r");
    if (SecurityQuestionsPointer == NULL){
        printf("\n\tError Resetting Password !\n");
        printf("\n\tContact Administration Department !\n");
        main();
    }
    else{
        while(fscanf(SecurityQuestionsPointer, "%s %s", HallTicketChecker, SQChecker) != EOF ){
            if ( (strcmp(HallTicketChecker,HallTicketNo) == 0) && (strcmp(SQChecker,SQ) == 0) ){
                fclose(SecurityQuestionsPointer);
                return 1;
            }
        }
        fclose(SecurityQuestionsPointer);
        return 0;
    }
}

int CheckSecurityAnswer(char HallTicketNo[], char SecurityAnswer[]){
    char SecurityAnswerChecker[50];
    char HallTicketChecker[22];
    FILE *SecurityAnswerPointer = fopen("Security_Answers.txt","r");
    if (SecurityAnswerPointer == NULL){
        printf("\n\tError Resetting Password !\n\n\tContact Administration Department !\n");
        main();
    }
    else{
        while(fscanf(SecurityAnswerPointer, "%s %s", HallTicketChecker, SecurityAnswerChecker) != EOF ){
            if (strcmp(HallTicketChecker,HallTicketNo) == 0 && strcmp(SecurityAnswerChecker,SecurityAnswer) == 0 ){
                fclose(SecurityAnswerPointer);
                return 1;
            }
        }
        fclose(SecurityAnswerPointer);
        return 0;
    }
}

void DisplaySecurityQestions(int SQ){
    switch (SQ){
    case 1:
        printf("%s\n",SQ1);
        break;
    case 2:
        printf("%s\n",SQ2);
        break;
    case 3:
        printf("%s\n",SQ3);
        break;
    case 4:
        printf("%s\n",SQ4);
        break;
    case 5:
        printf("%s\n",SQ5);
        break;
    }
}

void ResetPassword(char HallTicketNo[]){
    char SecurityAnswer[25];
    printf("Enter The Security Question You Selected While Creating Account : \n\n");
    int SQCh = SelectSecurityQuestion();
    char SQChoice[4];
    switch (SQCh){
    case 1:
        strcpy(SQChoice,"One");
        break;
    case 2:
        strcpy(SQChoice,"Two");
        break;
    case 3:
        strcpy(SQChoice,"Three");
        break;
    case 4:
        strcpy(SQChoice,"Four");
        break;
    case 5:
        strcpy(SQChoice,"Five");
        break;
    }

    if (CheckSecurityQuestion(HallTicketNo,SQChoice)){
        printf("Enter Answer : ");
        gets(SecurityAnswer);
        fflush(stdin);
        if (CheckSecurityAnswer(HallTicketNo,SecurityAnswer)){
            printf("\n\tSecurity Answer Matched\n\n\tYou Can Reset Your Password\n\n");
            ChangePassword();
        }
        else{
            printf("\n\tSecurity Answer Doesn't Match\n\n\t Please Contact Administration Department To Reset Your Password\n\n\n");
            printf("Exiting Program \n\n\n\t\t\t\t\t\t\t Thank You");
        }
    }
    else{
        printf("\n\tThe Security Question Doesn't Match\n\n\t Please Contact Administration Department To Reset Your Password\n\n");
        printf("Exiting Program \n\n\n\t\t\t\t\t\t\t Thank You");
    }
}

void ChangePassword(){
    FILE *ChangePasswordPointer;
    ChangePasswordPointer = fopen("Emails_Passwords.txt","a+");
    if (ChangePasswordPointer == NULL){
        printf("\n\tAn Error Occured! Try After A While..\n\n");
        return;
    }
    else{
        fprintf(ChangePasswordPointer,"\n%s ",stux.HallTicketNo);
        Password : printf("Enter New Password : ");
        gets(stux.Passwordx);
        fflush(stdin);
        printf("Re-Enter Password : ");
        gets(stux.Passwordy);
        fflush(stdin);
        if(strcmp(stux.Passwordx,stux.Passwordy) == 0){
            strcpy(stux.Password,stux.Passwordx);
            fprintf(ChangePasswordPointer,"%s",stux.Password);
            fclose(ChangePasswordPointer);
            printf("\n\tPassword Changed Successfully !!\n\n\n");
            printf("\n\tNow Please LogIn\n\n");
            LogIn();
        }
        else{
            printf("\n\tPasswords Donot Match !!! \n\n");
            goto Password;
        }
    }
}

void SelectChoice(){
    int Choice;
    printf("\n\n-------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\t\t\tWelcome To Home Page :\n\n\n"); 
    printf("1.Profile\n");
    printf("2.Attendence\n");
    printf("3.Fee Payment\n"); 
    printf("4.Internals\n");
    printf("5.Grievence\n");
    printf("6.Change Password\n");
    printf("7.Exit\n");
    printf("\nSelect An Option (1-7): ");
    scanf("%d",&Choice);
    fflush(stdin);
    printf("\n\n");
    switch (Choice){
    case 1:
        Profile();
        break;
    case 2:
        Attendence();
        break;
    case 3:
        FeePayment();
        break;
    case 4:
        Internals();
        break;
    case 5:
        Grievence();
        break;
    case 6:
        ChangePassword();
        SelectChoice();
        break;
    case 7: 
        printf("\n\t\t\t\t\t\t\tThank You\n\n\t\t\t\t\t\t\tProgram Exited Successfully ! \n");
        break;
    default:
        printf("\tInvalid Input. Try Again !!! \n\n");
        SelectChoice();
    }
}

int main(){
    printf("\n\n\n\t\t\t\t\t\t\tWelcome To EduPortal\t\t\t\n\n");
    LogInOptions();
    return 0;
}