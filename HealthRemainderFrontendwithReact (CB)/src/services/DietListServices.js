import axios from 'axios';

const DIETINFO_REST_URL= 'http://localhost:8086/healthreminder/diet_info_find_all' ;
const DIETINFO_UPDATE_URL='http://localhost:8086/healthreminder/diet_info_update';
const DIETINFO_ADD_URL='http://localhost:8086/healthreminder/create_diet';
const DIETINFO_DELETE_URL='http://localhost:8086/healthreminder/delete_diet_by_bmi';
const DIETINFO_FIND_URL='http://localhost:8086/healthreminder/diet_info_find';

class DietListServices{

    viewInfo(){
       return axios.get(DIETINFO_REST_URL);
    }

    updateInfo(bmiValue, dietInformation){
        return axios.put(DIETINFO_UPDATE_URL + '/' + bmiValue + '/info/' + dietInformation);
    }

    addInfo(h){
        return axios.post(DIETINFO_ADD_URL, h);
    }

    deleteInfo(bmi){
        return axios.delete(DIETINFO_DELETE_URL + '/' + bmi);
    }

    findInfo(bmi){
        return axios.get(DIETINFO_FIND_URL + '/' + bmi);
    }
}

export default new DietListServices();