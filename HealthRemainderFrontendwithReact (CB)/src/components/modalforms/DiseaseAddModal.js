import React, { Component } from 'react';
import Form from 'react-bootstrap/Form';
import Modal from 'react-bootstrap/Modal';
import Button from 'react-bootstrap/button';
import DiseaseListServices from '../../services/DiseaseListServices';


class DiseaseAddModal extends Component {
    constructor(props) {
        super(props)
    
        this.state = {
            id:null,
            name:"",
            info:"",
            keys:"",
            errors: {}
        }
        this.changeIdHandler = this.changeIdHandler.bind(this);
        this.changeNameHandler = this.changeNameHandler.bind(this);
        this.changeInfoHandler = this.changeInfoHandler.bind(this);
        this.changeKeysHandler = this.changeKeysHandler.bind(this);
        this.addDisease = this.addDisease.bind(this);
    }

    handleValidation(){
      let id = this.state.id;
      let name = this.state.name;
      let info = this.state.info;
      let keys = this.state.keys;
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
            errors["id"] = "Should be greater than 1";
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
          if(!name.match(/.*[a-zA-Z]+.*/)){
              formIsValid = false;
              errors["name"] = "Please enter atleast one Alphabet";
           }    
      }

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

     //Keys
     if(!keys){
      formIsValid = false;
      errors["keys"] = "Cannot be empty";
    }

   if(typeof keys !== "undefined"){
       if(keys.length<5 || keys.length>15){
         formIsValid = false;
         errors["keys"] = "Should be between 5 and 15 characters";
       }       
       if(!keys.match(/.*[a-zA-Z]+.*/)){
           formIsValid = false;
           errors["keys"] = "Please enter atleast one Alphabet";
        }    
   }

   this.setState({errors: errors});
     return formIsValid;
  }
    
      changeIdHandler= (event) => {
        this.setState({id: event.target.value});
        console.log(this.state.id);
      }
    
      changeNameHandler= (event) => {
        this.setState({name: event.target.value});
        console.log(this.state.name);
    
      }
    
      changeInfoHandler= (event) => {
        this.setState({info: event.target.value});
        console.log(this.state.info);
    
      }
      changeKeysHandler= (event) => {
        this.setState({keys: event.target.value});
        console.log(this.state.keys);
    
      }
      addDisease = () => {
        let disease={diseaseId: this.state.id, diseaseName: this.state.name, diseaseInfo: this.state.info, diseaseKeys: this.state.keys};
        console.log('disease =>' + JSON.stringify(disease));
        if(this.handleValidation()){
          DiseaseListServices.addDisease(disease).then( res => {
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
            show={this.props.isAddOpen} 
            onHide={this.props.closeAddModal}
          >
          <Modal.Header closeButton>
            <Modal.Title>Add New Disease</Modal.Title>
          </Modal.Header>
          <Modal.Body>
              <Form.Group >
                  <Form.Label>ID </Form.Label>
                  <Form.Control type="number" onChange={this.changeIdHandler} value={this.state.id} placeholder="Disease ID"/>   
                  <span style={{color: "red"}}>{this.state.errors["id"]}</span>                   
              </Form.Group>
              <Form.Group >
                  <Form.Label>Name </Form.Label>
                  <Form.Control type="text" onChange={this.changeNameHandler} value={this.state.name} placeholder="Enter Disease Name"/>           
                  <span style={{color: "red"}}>{this.state.errors["name"]}</span>           
              </Form.Group>
              <Form.Group >
                  <Form.Label>Information </Form.Label>
                  <Form.Control type="text" onChange={this.changeInfoHandler} value={this.state.info} placeholder="Enter some Information"/> 
                  <span style={{color: "red"}}>{this.state.errors["info"]}</span>                     
              </Form.Group>
              <Form.Group >
                  <Form.Label>Keys </Form.Label>
                  <Form.Control type="text" onChange={this.changeKeysHandler} value={this.state.keys} placeholder="Enter a Keyword for the Disease"/>           
                  <span style={{color: "red"}}>{this.state.errors["keys"]}</span>           
              </Form.Group>
          </Modal.Body>
          <Modal.Footer>
              <Button variant="primary" type="submit" onClick={() => {this.addDisease();}}>
                  Submit
              </Button>
          </Modal.Footer>
        </Modal>
        </div>
        )
      }
    }

export default DiseaseAddModal;