import React, { Component } from 'react';
import Form from 'react-bootstrap/Form';
import Modal from 'react-bootstrap/Modal';
import Button from 'react-bootstrap/button';
import AppointmentSlotServices from '../../services/AppointmentSlotServices';
import DatePicker from 'react-datepicker';
import 'react-datepicker/dist/react-datepicker.css'
import TimePicker from 'react-time-picker';

class AppointmentSlotAddModal extends Component {
    constructor(props) {
        super(props)
    
        this.state = {
            id:null,
            date:null,
            name:"",
            startTime:null,
            endTime:null,
            errors: {}
        }
        this.changeIdHandler = this.changeIdHandler.bind(this);
        this.changeDateHandler = this.changeDateHandler.bind(this);
        this.changeStartTimeHandler = this.changeStartTimeHandler.bind(this);
        this.changeEndTimeHandler = this.changeEndTimeHandler.bind(this);
        this.changeNameHandler=this.changeNameHandler.bind(this);
        this.addSlot = this.addSlot.bind(this);
    }

    handleValidation(){
      let id = this.state.id;
      let name = this.state.name;
      let date = this.state.date;
      let startTime = this.state.startTime;
      let endTime = this.state.endTime;
      let errors = {};
      let formIsValid = true;
  
      //ID
      if(!id){
         formIsValid = false;
         errors["id"] = "Cannot be empty";
      }
  
      if(typeof id !== "undefined"){
          if(id<1){
            formIsValid = false;
            errors["id"] = "Should be atleast 1";
          }        
      }
  
      //Name
      if(!name){
         formIsValid = false;
         errors["name"] = "Cannot be empty";
      }
  
      if(typeof name !== "undefined"){
          if(name.length<5 || name.length>100){
            formIsValid = false;
            errors["name"] = "Should be between 5 and 100 characters";
          }       
          if(!name.match(/[A-Za-z]+/)){
              formIsValid = false;
              errors["name"] = "Please enter only Alphabets";
           }    
      }

      //Date
      if(!date){
        formIsValid = false;
        errors["date"] = "Cannot be empty";
     }

     //Start time
     if(!startTime){
      formIsValid = false;
      errors["startTime"] = "Cannot be empty";
   }

   //End time
   if(!endTime){
    formIsValid = false;
    errors["endTime"] = "Cannot be empty";
 }
  
     this.setState({errors: errors});
     return formIsValid;
  }
    
      changeIdHandler= (event) => {
        this.setState({id: event.target.value});
        console.log(this.state.id);
      }
    
      changeDateHandler= (date) => {
        this.setState({date: date});
        console.log(this.state.date);
    
      }
    
      changeStartTimeHandler= (time) => {
        this.setState({startTime: time});
        console.log(this.state.startTime);
    
      }
      changeEndTimeHandler= (time) => {
        this.setState({endTime: time});
        console.log(this.state.endTime);
    
      }
      changeNameHandler= (event) => {
        this.setState({name: event.target.value});
        console.log(this.state.name);
    
      }
      addSlot = () => {
        let slot={pk:{doctorId: this.state.id, doctorDate: this.state.date}, doctorName:this.state.name,doctorStartTime: this.state.startTime, doctorEndTime: this.state.endTime};
        console.log('slot =>' + JSON.stringify(slot));
        if(this.handleValidation()){
          AppointmentSlotServices.addSlot(slot).then( res => {
            console.log(res);
            window.location.reload();
        });
          alert("Slot Successfully added!");
       }else{
          alert("Form has errors.")
       }
      }
    
      render(){
        return(
            <div>
          <Modal 
            show={this.props.isOpen} 
            onHide={this.props.closeModal}
          >
          <Modal.Header closeButton>
            <Modal.Title>Add New Slot</Modal.Title>
          </Modal.Header>
          <Modal.Body>
              <Form.Group >
                  <Form.Label>Doctor ID </Form.Label>
                  <Form.Control type="number" onChange={this.changeIdHandler} value={this.state.id} placeholder="Doctor ID"/>   
                  <span style={{color: "red"}}>{this.state.errors["id"]}</span>        
              </Form.Group>
              <Form.Group >
                  <Form.Label>Doctor Name </Form.Label>
                  <Form.Control type="text" onChange={this.changeNameHandler} value={this.state.name} placeholder="Enter Doctor Name"/> 
                  <span style={{color: "red"}}>{this.state.errors["name"]}</span> 
              </Form.Group>
              <Form.Group >
                  <Form.Label>Date </Form.Label><br></br>
                  <DatePicker selected={this.state.date} onChange={this.changeDateHandler} minDate={new Date()} dateFormat='MM/dd/yyyy' placeholder="select the date"/>           
                  <span style={{color: "red"}}>{this.state.errors["date"]}</span>    
              </Form.Group>
              <Form.Group >
                  <Form.Label>Start Time </Form.Label><br></br>
                  <TimePicker selected={this.state.startTime} format='HH:mm' disableClock={true}  onChange={this.changeStartTimeHandler} placeholder="Enter start time"/>           
                  <span style={{color: "red"}}>{this.state.errors["startTime"]}</span>    
              </Form.Group>
              <Form.Group >
                  <Form.Label>End Time </Form.Label><br></br>
                  <TimePicker selected={this.state.endTime} format='HH:mm' disableClock={true}  onChange={this.changeEndTimeHandler} placeholder="Enter end time"/>           
                  <span style={{color: "red"}}>{this.state.errors["endTime"]}</span>    
              </Form.Group>
          </Modal.Body>
          <Modal.Footer>
              <Button variant="primary" type="submit" onClick={() => {this.addSlot();}}>
                  Submit
              </Button>
          </Modal.Footer>
        </Modal>
        </div>
        )
      }
    }

export default AppointmentSlotAddModal;