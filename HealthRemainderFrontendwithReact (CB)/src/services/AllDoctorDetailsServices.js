import axios from 'axios';

const DOCTORS_REST_URL= 'http://localhost:8086/healthreminder/getAllDoctors' ;
const DOCTOR_GET_URL= 'http://localhost:8086/healthreminder/getDoctorById' ;
const DOCTOR_ADD_REST_URL= 'http://localhost:8086/healthreminder/createDoctor' ;
const DOCTOR_UPDATE_URL= 'httlp://localhost:8086/healthreminder/updateDoctorNameById/'
class AllDoctorsDetails{

    getAllDoctors(){
       return axios.get(DOCTORS_REST_URL);
    }

    getDoctorById(id){
        return axios.get(DOCTOR_GET_URL + "/" + id);
    }

    createDoctor(h){
        return axios.post(DOCTOR_ADD_REST_URL, h);
    }

    updateDoctor(id,name,spec){
        return axios.put(DOCTOR_UPDATE_URL+id+'/'+name+'/true/Certified/'+spec);
    }

}

export default new AllDoctorsDetails();