import React, { Component } from 'react';
import Form from 'react-bootstrap/Form';
import Modal from 'react-bootstrap/Modal';
import Button from 'react-bootstrap/button';
import DietListServices from '../../services/DietListServices';

class DietInfoDeleteModal extends Component {
    constructor(props) {
        super(props)
    
        // this.state = {
        //     bmi:null
        // }
        // this.changeBmiHandler = this.changeBmiHandler.bind(this);
        this.deleteDiet = this.deleteDiet.bind(this);
    }
    
    //   changeBmiHandler= (event) => {
    //     this.setState({bmi: event.target.value});
    //     console.log(this.state.bmi);
    //   }
    
      deleteDiet = () => {
        //e.preventDefault();
        console.log('id => ' + JSON.stringify(this.props.bmi));
        DietListServices.deleteInfo(this.props.bmi).then( res => {
            console.log(res);
            window.location.reload();
        });
      }
    
      render(){
        return(
            <div>
          <Modal 
            show={this.props.isDeleteOpen} 
            onHide={this.props.closeDeleteModal}
          >
          <Modal.Header closeButton>
            <Modal.Title>Delete Diet Plan</Modal.Title>
          </Modal.Header>
          <Modal.Body>
              <Form.Group >
                <div> Are you sure you want to delete {this.props.bmi}?</div>
              </Form.Group>
          </Modal.Body>
          <Modal.Footer>
              <Button variant="primary" type="submit" onClick={() => {this.deleteDiet();}}>
              Yes
              </Button>
              <Button variant="primary"  onClick={() => {this.props.closeDeleteModal()}}>
                  No
              </Button>
          </Modal.Footer>
        </Modal>
        </div>
        )
      }
    }

export default DietInfoDeleteModal;