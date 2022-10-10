import Form from 'react-bootstrap/Form'
import Modal from 'react-bootstrap/Modal'
import Button from 'react-bootstrap/button'
import React, { Component } from 'react'
import { withRouter } from 'react-router-dom';
import DiseaseListServices from '../../services/DiseaseListServices'


class DiseaseUpdateModal extends Component {
  constructor(props) {
    super(props)

    this.state = {
        //id:null,
        info:"",
        errors: {}
    }
    //this.changeIdHandler = this.changeIdHandler.bind(this);
    this.changeInfoHandler = this.changeInfoHandler.bind(this);
    this.updateDisease = this.updateDisease.bind(this);
}

handleValidation(){
  let info = this.state.info;
  let errors = {};
  let formIsValid = true;

  //Info
  if(!info){
    formIsValid = false;
    errors["info"] = "Cannot be empty";
 }

 if(typeof info !== "undefined"){
     if(info.length<5 || info.length>250){
       formIsValid = false;
       errors["info"] = "Should be between 5 and 250 characters";
     }       
     if(!info.match(/.*[a-zA-Z]+.*/)){
         formIsValid = false;
         errors["info"] = "Please enter atleast one Alphabet";
      }    
 }
  this.setState({errors: errors});
  return formIsValid;
 }

  // changeIdHandler= (event) => {
  //   this.setState({id: event.target.value});
  //   console.log(this.state.id);
  // }

  changeInfoHandler= (event) => {
    this.setState({info: event.target.value});
    console.log(this)

  }

  updateDisease = () => {
    //e.preventDefault();
    console.log('id => ' + JSON.stringify(this.props.id));
    if(this.handleValidation()){
      DiseaseListServices.updateDiseaseInfo(this.props.id, this.state.info).then( res => {
        console.log(res);
        window.location.reload();
    });
      alert("Form submitted");
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
        <Modal.Title>Update Disease Information</Modal.Title>
      </Modal.Header>
      <Modal.Body>
          <Form.Group >
              <Form.Label>Information </Form.Label>
              <Form.Control type="text" onChange={this.changeInfoHandler} value={this.state.info} placeholder="Enter Information"/>           
              <span style={{color: "red"}}>{this.state.errors["info"]}</span>                     
          </Form.Group>
          <Form.Group>
            <div>
              Are you sure you want to Update information for ID {this.props.id}?
            </div>
          </Form.Group>
      </Modal.Body>
      <Modal.Footer>
          <Button variant="primary" type="submit" onClick={() => {this.updateDisease();}}>
              Yes
          </Button>
          <Button variant="primary"  onClick={() => {this.props.closeModal()}}>
                  No
              </Button>
      </Modal.Footer>
    </Modal>
    </div>
    )
  }
}

export default withRouter(DiseaseUpdateModal);