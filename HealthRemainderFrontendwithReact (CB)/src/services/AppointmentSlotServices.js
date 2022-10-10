import axios from 'axios';

const SLOT_REST_URL= 'http://localhost:8086/healthreminder/getAllSlots' ;
const SLOT_ADD_URL='http://localhost:8086/healthreminder/createAppointmentSlot';


class AppointmentSlotServices{

    viewSlots(){
       return axios.get(SLOT_REST_URL);
    }

    addSlot(s){
        return axios.post(SLOT_ADD_URL,s);
    }
}

export default new AppointmentSlotServices();