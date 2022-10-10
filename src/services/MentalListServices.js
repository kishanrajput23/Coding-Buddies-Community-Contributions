import axios from 'axios';

const HEALTHTIP_REST_URL= 'http://localhost:8086/healthreminder/viewTips' ;
const HEALTHTIP_UPDATE_URL='http://localhost:8086/healthreminder/updateTips';
const HEALTHTIP_ADD_URL='http://localhost:8086/healthreminder/addTips';
const HEALTHTIP_DELETE_URL='http://localhost:8086/healthreminder/deleteTips';

class MentalListServices{

    viewTips(){
       return axios.get(HEALTHTIP_REST_URL);
    }

    updateTips(rating,tip){
        return axios.post(HEALTHTIP_UPDATE_URL + '/' + rating + '/' + tip);
    }

    addTips(h){
        return axios.post(HEALTHTIP_ADD_URL, h);
    }

    deleteTips(rating){
        return axios.delete(HEALTHTIP_DELETE_URL + '/' + rating);
    }
}

export default new MentalListServices();