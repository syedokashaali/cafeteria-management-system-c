#include <stdio.h> 

#include <string.h> 

  

#define MAX 100 

  

// Structure to store inventory item 

struct Item { 

    int id; 

    char name[30]; 

    char category[20];   // Snack / Drink / Ingredient 

    float quantity; 

    char unit[10];       // kg / pcs / liters 

    float reorderLevel; 

}; 

  

struct Item inventory[MAX]; 

int count = 0; 

  

// Function declarations 

void addItem(); 

void updateItem(); 

void deleteItem(); 

void searchItem(); 

void displayItems(); 

void lowStockAlert(); 

  

int main() { 

    int choice; 

  

    while (1) { 

        printf("\n===== College Canteen Inventory System =====\n"); 

        printf("1. Add Item\n"); 

        printf("2. Update Item Quantity\n"); 

        printf("3. Delete Item\n"); 

        printf("4. Search Item\n"); 

        printf("5. Display All Items\n"); 

        printf("6. Low Stock Alert\n"); 

        printf("7. Exit\n"); 

        printf("Enter your choice: "); 

        scanf("%d", &choice); 

  

        switch (choice) { 

            case 1: addItem(); break; 

            case 2: updateItem(); break; 

            case 3: deleteItem(); break; 

            case 4: searchItem(); break; 

            case 5: displayItems(); break; 

            case 6: lowStockAlert(); break; 

            case 7: 

                printf("Exiting system...\n"); 

                return 0; 

            default: 

                printf("Invalid choice! Try again.\n"); 

        } 

    } 

} 

  

// Add new item 

void addItem() { 

    if (count >= MAX) { 

        printf("Inventory full!\n"); 

        return; 

    } 

  

    printf("Enter Item ID: "); 

    scanf("%d", &inventory[count].id); 

  

    printf("Enter Item Name: "); 

    scanf(" %[^\n]", inventory[count].name); 

  

    printf("Enter Category (Snack/Drink/Ingredient): "); 

    scanf(" %[^\n]", inventory[count].category); 

  

    printf("Enter Quantity: "); 

    scanf("%f", &inventory[count].quantity); 

  

    printf("Enter Unit (kg/pcs/liters): "); 

    scanf(" %[^\n]", inventory[count].unit); 

  

    printf("Enter Reorder Level: "); 

    scanf("%f", &inventory[count].reorderLevel); 

  

    count++; 

    printf("Item added successfully!\n"); 

} 

  

// Update item quantity 

void updateItem() { 

    int id, i; 

    printf("Enter Item ID to update: "); 

    scanf("%d", &id); 

  

    for (i = 0; i < count; i++) { 

        if (inventory[i].id == id) { 

            printf("Enter new quantity: "); 

            scanf("%f", &inventory[i].quantity); 

            printf("Item updated successfully!\n"); 

            return; 

        } 

    } 

    printf("Item not found!\n"); 

} 

  

// Delete item 

void deleteItem() { 

    int id, i, j; 

    printf("Enter Item ID to delete: "); 

    scanf("%d", &id); 

  

    for (i = 0; i < count; i++) { 

        if (inventory[i].id == id) { 

            for (j = i; j < count - 1; j++) { 

                inventory[j] = inventory[j + 1]; 

            } 

            count--; 

            printf("Item deleted successfully!\n"); 

            return; 

        } 

    } 

    printf("Item not found!\n"); 

} 

  

// Search item 

void searchItem() { 

    int id, i; 

    printf("Enter Item ID to search: "); 

    scanf("%d", &id); 

  

    for (i = 0; i < count; i++) { 

        if (inventory[i].id == id) { 

            printf("\nItem Found:\n"); 

            printf("ID: %d\n", inventory[i].id); 

            printf("Name: %s\n", inventory[i].name); 

            printf("Category: %s\n", inventory[i].category); 

            printf("Quantity: %.2f %s\n", inventory[i].quantity, inventory[i].unit); 

            printf("Reorder Level: %.2f\n", inventory[i].reorderLevel); 

            return; 

        } 

    } 

    printf("Item not found!\n"); 

} 

  

// Display all items 

void displayItems() { 

    int i; 

    if (count == 0) { 

        printf("Inventory is empty!\n"); 

        return; 

    } 

  

    printf("\nID\tName\t\tCategory\tQty\tUnit\tReorder\n"); 

    printf("-------------------------------------------------------------\n"); 

  

    for (i = 0; i < count; i++) { 

        printf("%d\t%s\t\t%s\t\t%.2f\t%s\t%.2f\n", 

               inventory[i].id, 

               inventory[i].name, 

               inventory[i].category, 

               inventory[i].quantity, 

               inventory[i].unit, 

               inventory[i].reorderLevel); 

    } 

} 

  

// Low stock alert 

void lowStockAlert() { 

    int i, found = 0; 

    printf("\nLow Stock Items:\n"); 

  

    for (i = 0; i < count; i++) { 

        if (inventory[i].quantity <= inventory[i].reorderLevel) { 

            printf("⚠ %s (ID: %d) is low in stock!\n", 

                   inventory[i].name, inventory[i].id); 

            found = 1; 

        } 

    } 

  

    if (!found) { 

        printf("No low-stock items.\n"); 

    } 

} 
