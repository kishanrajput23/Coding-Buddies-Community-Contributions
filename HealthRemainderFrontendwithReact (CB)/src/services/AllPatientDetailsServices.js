import axios from 'axios';

const PATIENTS_REST_URL= 'http://localhost:8086/healthreminder/patients' ;
const PATIENT_REST_URL= 'http://localhost:8086/healthreminder/patient' ;
const PATIENT_ADD_REST_URL= 'http://localhost:8086/healthreminder/patient' ;

class AllPatientDetails{

    getPatients(){
       return axios.get(PATIENTS_REST_URL);
    }

    getPatient(id){
        return axios.get(PATIENT_REST_URL + "/" + id);
    }

    postPatient(h){
        return axios.post(PATIENT_ADD_REST_URL, h);
    }

    updatePatient(p){
        return axios.put(PATIENT_REST_URL, p);
    }

}

export default new AllPatientDetails();