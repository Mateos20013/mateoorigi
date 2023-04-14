#include <stdio.h>
#include <string.h>

int main()
{
    int item;
    int opcion;
    float subtotal = 0;
    float descuento = 0;
    float total = 0;
    int cantidad;
    char respuesta;
    char nombre[50];
    char cedula[50];
    char detallesFactura[1500] = "";
    char charValue[200];

    do
    {
        printf("\n--Menú--\n");
        printf("1. Facturar item\n");
        printf("2. Imprimir factura\n");
        printf("3. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            do
            {
                item = 0;

                printf("\n--item--\n");
                printf("1. Llantas (Precio: $150)\n");
                printf("2. Kit Pastillas de freno (Precio: $55)\n");
                printf("3. Kit de embrague (Precio: $180)\n");
                printf("4. Faro (Precio: $70)\n");
                printf("5. Radiador (Precio: $120)\n");
                printf("Seleccione un item: ");
                scanf("%d", &item);

                switch (item)
                {
                case 1:
                    printf("Ingrese la cantidad de llantas: ");
                    scanf("%d", &cantidad);
                    subtotal += cantidad * 150.0;
                    sprintf(charValue, "Llantas\t\t\t\t%d\t\t%.2f\n", cantidad, cantidad * 150.0);
                    strcat(detallesFactura, charValue);
                    break;
                case 2:
                    printf("Ingrese la cantidad de kits de pastillas de freno: ");
                    scanf("%d", &cantidad);
                    subtotal += cantidad * 55.0;
                    sprintf(charValue, "Kit Pastillas de freno\t\t%d\t\t%.2f\n", cantidad, cantidad * 55.0);
                    strcat(detallesFactura, charValue);
                    break;
                case 3:
                    printf("Ingrese la cantidad de kits de embrague: ");
                    scanf("%d", &cantidad);
                    subtotal += cantidad * 180;
                    sprintf(charValue, "Faro\t\t\t\t%d\t\t%.2f\n", cantidad, cantidad * 180.0);
                    strcat(detallesFactura, charValue);
                    break;
                case 4:
                    printf("Ingrese la cantidad de faros: ");
                    scanf("%d", &cantidad);
                    subtotal += cantidad * 70;
                    sprintf(charValue, "Faro\t\t\t\t%d\t\t%.2f\n", cantidad, cantidad * 70.0);
                    strcat(detallesFactura, charValue);
                    break;
                case 5:
                    printf("Ingrese la cantidad de radiadores: ");
                    scanf("%d", &cantidad);
                    subtotal += cantidad * 120;
                    sprintf(charValue, "Radiador\t\t\t%d\t\t%.2f\n", cantidad, cantidad * 120.0);
                    strcat(detallesFactura, charValue);
                    break;
                default:
                    printf("Opción inválida\n");
                    break;
                }

                printf("¿Desea facturar otro producto? (S/N): ");
                scanf(" %c", &respuesta);
            } while (respuesta == 'S' || respuesta == 's');
            break;
        case 2:
            if (subtotal == 0)
            {
                printf("No hay productos para facturar\n");
            }
            else
            {
                printf("\n--Factura--\n");
                printf("Nombre del comprador: ");
                scanf("%s", nombre);
                printf("Número de cédula del comprador: ");
                scanf("%s", cedula);

                printf("Producto\t\t\tCantidad\tPrecio\n");
                printf("------------------------------------------------------\n");
                printf("%s", detallesFactura);
                printf("-------------------------------------------------------\n");
                if (subtotal <= 500)
                {
                    descuento = 0;
                }
                else if (subtotal <= 1000)
                {
                    descuento = subtotal * 0.04;
                }
                else if (subtotal <= 5000)
                {
                    descuento = subtotal * 0.07;
                }
                else
                {
                    descuento = subtotal * 0.09;
                }

                total = subtotal - descuento;

                printf("Subtotal\t\t\t\t\t$%.2f\n", subtotal);
                printf("Descuento (%.2f%%)\t\t\t\t$%.2f\n", descuento / subtotal * 100, descuento);
                printf("Total\t\t\t\t\t\t$%.2f\n", total);
            }


            printf("Presione cualquier tecla para continuar...\n");
            getchar(); // para limpiar el buffer del teclado
            getchar(); // para esperar a que el usuario presione una tecla
            break;
        case 3:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opción inválida\n");
            break;
        }

    } while (opcion != 3);

    return 0;
}
