import Form from 'react-bootstrap/Form'
import Modal from 'react-bootstrap/Modal'
import React, { Component } from 'react'
import { Link, withRouter } from 'react-router-dom';
import AllPatientDetailsServices from '../../services/AllPatientDetailsServices';

class PatientProfileModal extends Component {
  constructor(props) {
    super(props)

    this.state = {
        id: null,
        errors: {}
    }
    this.changeIdHandler = this.changeIdHandler.bind(this);
    this.findID = this.findID.bind(this);
  }

  handleValidation(){
    let id = this.state.id;
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

   this.setState({errors: errors});
   return formIsValid;
  }

  changeIdHandler= (event) => {
        this.setState({id: event.target.value});    
  }

  findID = () => {
    console.log('ID =>' + JSON.stringify(this.state.id));
    if(this.handleValidation()){
        AllPatientDetailsServices.getPatient(this.state.id).then( res => {
            if(res.data.errorCode){
                alert('Patient Not found so lets setup')
                window.location="/PatientProfileSet/";
            }
            else{
                alert('Patient found so lets update')
                window.location = "/PatientProfileUpdate/"+this.state.id;
            }
        })
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
        <Modal.Title>Set/Update Profile</Modal.Title>
      </Modal.Header>
      <Modal.Body>
          <Form.Group >
              <Form.Label>Patient ID </Form.Label>
              <Form.Control type="number" onChange={this.changeIdHandler} value={this.state.id} placeholder="Enter Patient ID"/>           
              <span style={{color: "red"}}>{this.state.errors["id"]}</span>           
          </Form.Group>
      </Modal.Body>
      <Modal.Footer>
        <Link  className="btn btn-primary" onClick={() => {this.findID();}}>Submit</Link>
      </Modal.Footer>
    </Modal>
    </div>
    )
  }
}

export default withRouter(PatientProfileModal);