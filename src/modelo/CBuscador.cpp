/*
    Proyecto: Drogueria - FPOO - Universidad del Valle
    Módulo: Búsqueda (GRUPO 6)

    ESTE ARCHIVO ES TUYO: reemplaza los STUB por la implementación real.
*/
#include "CBuscador.h"
using namespace std;

CBuscador::CBuscador(const CInventario& inventario_) : inventario(inventario_) {
}

/**
 * @brief Busca un medicamento por id.
 * @param id entero.
 * @return Puntero al medicamento que coincide en el id o nullptr. 
 */
const CMedicamento* CBuscador::porId(int id) const{
    const vector<CMedicamento>& medicamentos = inventario.getMedicamentos();
    for(size_t i = 0; i < medicamentos.size(); i++){
        if(medicamentos[i].getId() == id){
            return &medicamentos[i];
        }
    }
    return nullptr;
}

/**
 * @brief Busca medicamentos por el nombre.
 * @param texto string.
 * @return Vector de CMedicamento. 
 */
vector<CMedicamento> CBuscador::porNombre(string texto) const{
    const vector<CMedicamento>& medicamentos = inventario.getMedicamentos();
    vector<CMedicamento> coincidencias;

    for(char &c : texto){
        c = towlower(c);
    }

    for(size_t i = 0; i < medicamentos.size(); i++){
        string nombre = medicamentos[i].getNombre();
        for(char &c : nombre){
            c = tolower(c);
        }

        if(nombre.find(texto) != string::npos){
            coincidencias.push_back(medicamentos[i]);
        }
    }

    return coincidencias;
}

/**
 * @brief Filtra los medicamentos por un rango de precio.
 * @param minimo float, maximo float.
 * @return Vector de CMedicamento.
 */
vector<CMedicamento> CBuscador::porRangoPrecio(float minimo, float maximo) const{
    const vector<CMedicamento>& medicamentos = inventario.getMedicamentos();
    vector<CMedicamento> coincidencias;

    for(size_t i = 0; i < medicamentos.size(); i++){
        if(medicamentos[i].getPrecioDeVenta() >= minimo && medicamentos[i].getPrecioDeVenta() <= maximo){
            coincidencias.push_back(medicamentos[i]);
        }
    }

    return coincidencias;
}

/**
 * @brief Busca medicamentos con bajo stock (menor que umbral).
 * @param umbral int.
 * @return Vector de CMedicamento.
 */
vector<CMedicamento> CBuscador::conPocoStock(int umbral) const{
    const vector<CMedicamento>& medicamentos = inventario.getMedicamentos();
    vector<CMedicamento> coincidencias;

    for(const auto& med : medicamentos){
        if(med.getCantidadDisponible() < umbral){
            coincidencias.push_back(med);
        }
    }
    return coincidencias;
}
