import React,{Component} from 'react'
import ReactStars from 'react-rating-stars-component'
import {Modal,Button} from 'react-bootstrap'
import axios from 'axios'

class MentalRatingModal extends Component{
    constructor(props){
        super(props)
        this.state={
            patientId:0,
            rating:0,
            tip:'',
            tipFound:false,
            patientFound:true
        };
        this.ratingChanged=this.ratingChanged.bind(this);
        this.idchanged=this.idchanged.bind(this);
        this.handleSubmit=this.handleSubmit.bind(this);
    }
    ratingChanged(newRating){
        this.setState({rating:newRating})
        console.log(this.state.patientId)
    }
    idchanged(id){
        this.setState({patientId:id.target.value})
    }
    handleSubmit(){
        axios.get('http://localhost:8086/healthreminder/patient/'+this.state.patientId)
        .then(res=>{
            console.log(res)
            if(res.data.errorCode)
                {   this.setState({patientFound:false})
                    window.location=("/PatientProfileSet/")}
        })
        if(this.state.patientFound){
        var url_post= "http://localhost:8086/healthreminder/create_followup_mentalrating"
        const mentalObj = {patientId:this.state.patientId, mentalRating: this.state.rating}
        axios.get("http://localhost:8086/healthreminder/followup_mentalrating_find/"+this.state.patientId)
        .then(res=>{
            console.log(res.data)
            if(res.data.patientId!=null){
                axios.delete('http://localhost:8086/healthreminder/delete_mentarating_by_id/'+this.state.patientId)
                .then(res=>{
                    console.log('rating updated')
                })
        }
//else{
            axios.post(url_post,mentalObj)
            .then(res=>{
                console.log(res)
            })
  //      }
    })
    axios.get("http://localhost:8086/healthreminder/viewTips/"+this.state.rating)
    .then(res=>{
        console.log(res.data)
        this.setState({tipFound:true,tip:res.data.mentalTip})
    })}
    }
    render(){
        return(
            <>
            <Modal show={this.props.show} onHide={this.props.handleClose}>
            {!this.state.tipFound &&
            <>
        <Modal.Header closeButton>
          <Modal.Title>Enter your mental health rating</Modal.Title>
        </Modal.Header>
        <Modal.Body>
            <input type="number" placeholder="Enter patient id" onChange={this.idchanged}/>
            <ReactStars count={5} size={24} onChange={this.ratingChanged} activeColor='#ffd700'/>
        </Modal.Body>
        <Modal.Footer>
          <Button variant="primary" onClick={this.handleSubmit}>
            Save Changes
          </Button>
        </Modal.Footer></>}
        {this.state.tipFound && <>
        <Modal.Header closeButton>
            <Modal.Title>Tip for you</Modal.Title>
        </Modal.Header>
        <h3 style={{margin:'20px', textAlign:'center'}}>{this.state.tip}</h3>
        </>}
      </Modal>
            </>
        );
    }
}

export default MentalRatingModal;