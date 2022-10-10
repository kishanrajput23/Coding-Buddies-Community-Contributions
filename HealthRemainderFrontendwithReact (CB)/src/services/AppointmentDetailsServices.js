import axios from 'axios';

const APPOINTMENT_DETAILS_API_BASE_URL = "http://localhost:8086/healthreminder";

class AppointmentDetailsServices {

    getAppointmentDetailsByPatientId(patientId){
        return axios.get(APPOINTMENT_DETAILS_API_BASE_URL+'/findAppointmentByPatId/'+patientId);
    }

    
    getAppointmentDetailsByDoctorId(doctorId){
        return axios.get(APPOINTMENT_DETAILS_API_BASE_URL+'/findAppointmentByDocId/'+doctorId);
    }

    addAppointment(a){
        return axios.post(APPOINTMENT_DETAILS_API_BASE_URL+'/createAppointment',a);
    }
    
}

export default new AppointmentDetailsServices();