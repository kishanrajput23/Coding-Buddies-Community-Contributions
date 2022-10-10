import React, { Component } from 'react';
import Form from 'react-bootstrap/Form';
import Modal from 'react-bootstrap/Modal';
import Button from 'react-bootstrap/button';
import DietListServices from '../../services/DietListServices';


class DietInfoAddModal extends Component {
    constructor(props) {
        super(props)
    
        this.state = {
            bmi:null,
            diet:"",
            errors: {}
        }
        this.changeBmiHandler = this.changeBmiHandler.bind(this);
        this.changeDietHandler = this.changeDietHandler.bind(this);
        this.addDiet = this.addDiet.bind(this);
    }

    handleValidation(){
        let bmi = this.state.bmi;
        let diet = this.state.diet;
        let errors = {};
        let formIsValid = true;

        //BMI
        if(!bmi){
           formIsValid = false;
           errors["bmi"] = "Cannot be empty";
        }
  
        if(typeof bmi !== "undefined"){
            if(bmi<1 || bmi>4){
              formIsValid = false;
              errors["bmi"] = "Should be between 1 and 4";
            }        
        }
   
        //Diet
        if(!diet){
           formIsValid = false;
           errors["diet"] = "Cannot be empty";
        }
  
        if(typeof diet !== "undefined"){
            if(diet.length<5 || diet.length>200){
              formIsValid = false;
              errors["diet"] = "Should be between 5 and 200 characters";
            }       
            if(!diet.match(/^(?=.*[\w\d]).+/)){
                formIsValid = false;
                errors["diet"] = "Should have atleast 1 alphabet or digit";
             }    
        }

       this.setState({errors: errors});
       return formIsValid;
   }
    
      changeBmiHandler= (event) => {
        this.setState({bmi: event.target.value});
        console.log(this.state.bmi);
      }
    
      changeDietHandler= (event) => {
        this.setState({diet: event.target.value});
        console.log(this)
    
      }
    
      addDiet = () => {
        let dietInfo={bmiValue: this.state.bmi, diet: this.state.diet};
        console.log('dietInfo =>' + JSON.stringify(dietInfo));
        if(this.handleValidation()){
            DietListServices.addInfo(dietInfo).then( res => {
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
            <Modal.Title>Add New Diet</Modal.Title>
          </Modal.Header>
          <Modal.Body>
              <Form.Group >
                  <Form.Label>BMI Value </Form.Label>
                  <Form.Control type="number" onChange={this.changeBmiHandler} value={this.state.bmi} placeholder="BMI value input"/>
                  <span style={{color: "red"}}>{this.state.errors["bmi"]}</span>           
              </Form.Group>
              <Form.Group >
                  <Form.Label>Diet Information </Form.Label>
                  <Form.Control type="text" onChange={this.changeDietHandler} value={this.state.diet} placeholder="Enter the diet plan"/>           
                  <span style={{color: "red"}}>{this.state.errors["diet"]}</span>  
              </Form.Group>
          </Modal.Body>
          <Modal.Footer>
              <Button variant="primary" type="submit" onClick={() => {this.addDiet();}}>
                  Submit
              </Button>
          </Modal.Footer>
        </Modal>
        </div>
        )
      }
    }

export default DietInfoAddModal;