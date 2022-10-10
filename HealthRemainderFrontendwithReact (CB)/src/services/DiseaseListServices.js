import axios from 'axios';

const DISEASES_REST_URL= 'http://localhost:8086/healthreminder/viewDisease' ;
const DISEASES_UPDATE_URL='http://localhost:8086/healthreminder/updateDisease';
const DISEASES_ADD_URL='http://localhost:8086/healthreminder/addDisease';
const DISEASES_DELETE_URL='http://localhost:8086/healthreminder/deleteDisease';

class DiseaseListServices{

    viewDisease(){
       return axios.get(DISEASES_REST_URL);
    }

    updateDiseaseInfo(id,info){
        return axios.post(DISEASES_UPDATE_URL + '/' + id + '/' + info);
    }

    addDisease(d){
        return axios.post(DISEASES_ADD_URL,d);
    }

    deleteDisease(id){
        return axios.delete(DISEASES_DELETE_URL + '/' + id);
    }
}

export default new DiseaseListServices();