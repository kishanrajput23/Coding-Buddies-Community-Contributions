import React, { Component } from 'react';
import Form from 'react-bootstrap/Form';
import Modal from 'react-bootstrap/Modal';
import Button from 'react-bootstrap/button';
import MentalListServices from '../../services/MentalListServices';


class MentalAddModal extends Component {
    constructor(props) {
        super(props)
    
        this.state = {
            id:null,
            tip:"",
            errors: {}
        }
        this.changeRatingHandler = this.changeRatingHandler.bind(this);
        this.changeTipHandler = this.changeTipHandler.bind(this);
        this.addTips = this.addTips.bind(this);
    }

    handleValidation(){
      let id = this.state.id;
      let tip = this.state.tip;
      let errors = {};
      let formIsValid = true;

      //ID
      if(!id){
         formIsValid = false;
         errors["id"] = "Cannot be empty";
      }

      if(typeof id !== "undefined"){
          if(id<1 || id>5){
            formIsValid = false;
            errors["id"] = "Should be between 1 and 5";
          }        
      }
 
      //Tip
      if(!tip){
         formIsValid = false;
         errors["tip"] = "Cannot be empty";
      }

      if(typeof tip !== "undefined"){
          if(tip.length<5 || tip.length>200){
            formIsValid = false;
            errors["tip"] = "Should be between 5 and 200 characters";
          }       
          if(!tip.match(/.*[a-zA-Z]+.*/)){
              formIsValid = false;
              errors["tip"] = "Please enter atleast one Alphabet";
           }    
      }

     this.setState({errors: errors});
     return formIsValid;
  }
    
      changeRatingHandler= (event) => {
        this.setState({id: event.target.value});
        console.log(this.state.id);
      }
    
      changeTipHandler= (event) => {
        this.setState({tip: event.target.value});
        console.log(this)
    
      }
    
      addTips = () => {
        let mentalHealth={mentalRating: this.state.id, mentalTip: this.state.tip};
        console.log('mentalHealth =>' + JSON.stringify(mentalHealth));
        if(this.handleValidation()){
          MentalListServices.addTips(mentalHealth).then( res => {
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
            <Modal.Title>Add New Health Tip</Modal.Title>
          </Modal.Header>
          <Modal.Body>
              <Form.Group >
                  <Form.Label>Rating </Form.Label>
                  <Form.Control type="number" onChange={this.changeRatingHandler} value={this.state.id} placeholder="Health Rating input"/>           
                  <span style={{color: "red"}}>{this.state.errors["id"]}</span>           
              </Form.Group>
              <Form.Group >
                  <Form.Label>Content </Form.Label>
                  <Form.Control type="text" onChange={this.changeTipHandler} value={this.state.tip} placeholder="Enter a Tip"/>     
                  <span style={{color: "red"}}>{this.state.errors["tip"]}</span>                 
              </Form.Group>
          </Modal.Body>
          <Modal.Footer>
              <Button variant="primary" type="submit" onClick={() => {this.addTips();}}>
                  Submit
              </Button>
          </Modal.Footer>
        </Modal>
        </div>
        )
      }
    }

export default MentalAddModal;