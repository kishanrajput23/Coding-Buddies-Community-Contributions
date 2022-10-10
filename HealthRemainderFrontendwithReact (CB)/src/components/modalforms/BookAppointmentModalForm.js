import Form from "react-bootstrap/Form";
import Modal from "react-bootstrap/Modal";
import React, { Component } from "react";
import { withRouter } from "react-router-dom";
import AppointmentDetailsServices from "../../services/AppointmentDetailsServices";
import Button from "react-bootstrap/button";

class BookAppointmentModalForm extends Component {
  constructor(props) {
    super(props);
    this.state = {
     /* id: props.id,
      name: props.doctorName,
      date: props.pk.doctorDate,
      startTime: props.doctorStartTime,
      endTime: props.doctorEndTime, */
      patientId: null,
      patientName: "",
      errors: {}
    };
    this.changePatientIdHandler = this.changePatientIdHandler.bind(this);
    this.changePatientNameHandler = this.changePatientNameHandler.bind(this);
  }

  handleValidation(){
    let patientId = this.state.patientId;
    let patientName = this.state.patientName;
    let errors = {};
    let formIsValid = true;

    //patientId
    if(!patientId){
       formIsValid = false;
       errors["patientId"] = "Cannot be empty";
    }

    if(typeof patientId !== "undefined"){
        if(patientId<1){
          formIsValid = false;
          errors["patientId"] = "Should be atleast 1";
        }        
    }

    //patientName
    if(!patientName){
       formIsValid = false;
       errors["patientName"] = "Cannot be empty";
    }

    if(typeof patientName !== "undefined"){
        if(patientName.length<5 || patientName.length>100){
          formIsValid = false;
          errors["patientName"] = "Should be between 5 and 100 characters";
        }       
        if(!patientName.match(/[A-Za-z]+/)){
            formIsValid = false;
            errors["patientName"] = "Please enter only Alphabets";
         }    
    }

   this.setState({errors: errors});
   return formIsValid;
}

  changePatientIdHandler = (event) => {
    this.setState({ patientId: event.target.value });
  };

  changePatientNameHandler = (event) => {
    this.setState({ patientName: event.target.value });
  };

  addAppointment = () => {
    let appoint = {
      doctorId: this.props.id.pk.doctorId,
      patientId: this.state.patientId,
      patientName: this.state.patientName,
      doctorDate: this.props.id.pk.doctorDate,
      doctorName: this.props.id.doctorName,
      doctorStartTime:this.props.id.doctorStartTime,
      doctorEndTime: this.props.id.doctorEndTime,
    };
    console.log("appoint =>" + JSON.stringify(appoint));
    if(this.handleValidation()){
      AppointmentDetailsServices.addAppointment(appoint).then((res) => {
        console.log(res);
        window.location.reload();
      });
      alert("Appointment Successfully Booked!");
   }else{
      alert("Form has errors.")
   }
    
  };

  render() {
    return (
      <div>
        <Modal show={this.props.isOpen} onHide={this.props.closeModal}>
          <Modal.Header closeButton>
            <Modal.Title>Book Appointment</Modal.Title>
          </Modal.Header>
          <Modal.Body>
            <Form.Group>
              <Form.Label>Patient ID </Form.Label>
              <Form.Control
                type="number"
                onChange={this.changePatientIdHandler}
                value={this.state.patientId}
                placeholder="Enter the Patient Id"
              />
              <span style={{color: "red"}}>{this.state.errors["patientId"]}</span>                     
            </Form.Group>
            <Form.Group>
              <Form.Label>Patient Name</Form.Label>
              <Form.Control
                type="text"
                onChange={this.changePatientNameHandler}
                value={this.state.patientName}
                placeholder="Enter Patient Name"
              />
              <span style={{color: "red"}}>{this.state.errors["patientName"]}</span>
            </Form.Group>
            <Form.Group>
              <Form.Label>Doctor ID </Form.Label>
              <Form.Control type="text" value={this.props.id.pk.doctorId} />
            </Form.Group>
            <Form.Group>
              <Form.Label>Doctor Name </Form.Label>
              <Form.Control type="text" value={this.props.id.doctorName} />
            </Form.Group>
            <Form.Group>
              <Form.Label>Date </Form.Label>
              <br></br>
              <Form.Control type="text" value={this.props.id.pk.doctorDate} />
            </Form.Group>
            <Form.Group>
              <Form.Label>Start Time </Form.Label>
              <br></br>
              <Form.Control type="text" value={this.props.id.doctorStartTime} />
            </Form.Group>
            <Form.Group>
              <Form.Label>End Time </Form.Label>
              <br></br>
              <Form.Control type="text" value={this.props.id.doctorEndTime} />
            </Form.Group>
          </Modal.Body>
          <Modal.Footer>
            <Button
              variant="primary"
              type="submit"
              onClick={() => {
                this.addAppointment();
              }}
            >
              Submit
            </Button>
          </Modal.Footer>
        </Modal>
      </div>
    );
  }
}

export default withRouter(BookAppointmentModalForm);
