#include "Data.h"

string Data::fechaActual()
{
    /**
     * Obtiene la fecha y hora actual en formato SQL.
     * @return Fecha y hora actual en formato 'YYYY-MM-DD HH:MM:SS'.
     */
    time_t now = time(nullptr);
    tm *t = localtime(&now);
    ostringstream oss;
    oss << put_time(t, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

string Data::transformarFechaSinHora(const string &fecha)
{
    /**
     * Transforma una fecha en formato 'DD-MM-YYYY' a formato SQL.
     * @param fecha Fecha en formato 'DD-MM-YYYY'.
     * @return Fecha en formato 'YYYY-MM-DD'.
     */
    tm t = {};
    istringstream iss(fecha);
    iss >> get_time(&t, "%d-%m-%Y");
    if (iss.fail())
    {
        throw invalid_argument("El formato de la fecha debe ser 'DD-MM-YYYY'.");
    }
    ostringstream oss;
    oss << put_time(&t, "%Y-%m-%d");
    return oss.str();
}

string Data::transformarFechaConHora(const string &fechaHora)
{
    /**
     * Transforma una fecha y hora en formato 'DD-MM-YYYY HH:MM:SS' a formato SQL.
     * @param fechaHora Fecha y hora en formato 'DD-MM-YYYY HH:MM:SS'.
     * @return Fecha y hora en formato 'YYYY-MM-DD HH:MM:SS'.
     **/
    tm t = {};
    istringstream iss(fechaHora);
    iss >> get_time(&t, "%d-%m-%Y %H:%M:%S");
    if (iss.fail())
    {
        throw invalid_argument("El formato de la fecha y hora debe ser 'DD-MM-YYYY HH:MM:SS'.");
    }
    ostringstream oss;
    oss << put_time(&t, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}
