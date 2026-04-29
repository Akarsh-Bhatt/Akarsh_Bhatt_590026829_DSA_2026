/*
Write a C program to implement a hash function on student SAP-ID and categorize them in to their 10 families based on the last three digits. Example: Student with SAP-ID 5000423 belongs to family 9 and student with SAP-ID 5000425 belongs to family 2 based on last three digits. 
*/

#include <stdio.h>

// Function to calculate the family based on SAP-ID
int getStudentFamily(long sapId) {
    int lastThree = sapId % 1000;
    int d1 = lastThree / 100;         
    int d2 = (lastThree / 10) % 10;   
    int d3 = lastThree % 10;          
    
    int sum = d1 + d2 + d3;
    return (sum - 1) % 9 + 1;
}

int main() {
    long sapId;
    int family;

    printf("Enter Student SAP-ID: ");
    if (scanf("%ld", &sapId) != 1) {
        printf("Invalid input. Please enter a numeric SAP-ID.\n");
        return 1;
    }

    family = getStudentFamily(sapId);

    printf("------------------------------------\n");
    printf("SAP-ID: %ld\n", sapId);
    printf("Last three digits: %03ld\n", sapId % 1000);
    printf("Assigned Family: %d\n", family);
    printf("------------------------------------\n");

    return 0;
}
