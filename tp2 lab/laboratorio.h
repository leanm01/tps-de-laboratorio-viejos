typedef struct
{
 int id;
 char nombre[51];
 char apellido[51];
 float salario;
 int sector;
 int isEmpty;
}eEmpleados;

int informes();
/** \brief submenu
 *
 * \param
 * \param
 * \return respuesta
 *
 */


int cargarUnEmpleado(eEmpleados* empleados,int len);
/** \brief carga un empleado
 *
 * \param eEmpleados* empleados
 * \param int len
 * \return devuelve el empleado cargado
 *
 */

int encontrarEmpleadoPorId(eEmpleados* empleados, int , int);
/** \brief busca empleado por id
 *
 * \param eEmpleados* empleados
 * \param int len
 * \param int id
 * \return si es -1 es error, si es 0 esta bien
 *
 */

int mostrarEmpleados(eEmpleados* empleados, int len);
/** \brief muestra un empleado
 *
 * \param eEmpleados* empleados
 * \param int len
 * \return devuelve los empleados
 *
 */

int inicializadorLista(eEmpleados* empleados, int len );
/** \brief inicializa la lista de empleados
 *
 * \param eEmpleados* empleados
 * \param int len
 * \return devuelve a los empleados
 *
 */

int modificarEmpleados(eEmpleados* empleados,int len);
/** \brief modifica un empleado
 *
 * \param eEmpleados* empleados
 * \param int len
 * \return si es -1 es error, si es 0 esta bien
 *
 */

int crearNuevoId();
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int eliminarEmpleado(eEmpleados* empleados,int len);
/** \brief elimina un empleado
 *
 * \param eEmpleados* empleados
 * \param int len
 * \return si es -1 es error, si es 0 esta bien
 *
 */

void TotalPromedio(eEmpleados* empleados, int len);
/** \brief muestra el total y promedio de los empleados
 *
 * \param eEmpleados* empleados
 * \param int len
 * \return devuelve ese total y promedio de los empleados
 *
 */

void ordenamientoEmpleados(eEmpleados* empleados,int len);
/** \brief ordena a los empleados
 *
 * \param eEmpleados* empleados
 * \param int len
 * \return devuelve en orden a los empleados
 *
 */

