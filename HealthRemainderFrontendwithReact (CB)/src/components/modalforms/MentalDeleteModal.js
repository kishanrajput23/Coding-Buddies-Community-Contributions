import React, { Component } from 'react';
import Form from 'react-bootstrap/Form';
import Modal from 'react-bootstrap/Modal';
import Button from 'react-bootstrap/button';
import MentalListServices from '../../services/MentalListServices';

class MentalDeleteModal extends Component {
    constructor(props) {
        super(props)
    
        // this.state = {
        //     id:1
        // }
       // this.changeRatingHandler = this.changeRatingHandler.bind(this);
        this.deleteTips = this.deleteTips.bind(this);
    }
    
      // changeRatingHandler= (event) => {
      //   this.setState({id: event.target.value});
      //   console.log(this.state.id);
      // }
    
      deleteTips = () => {
        //e.preventDefault();
        console.log('id => ' + JSON.stringify(this.props.id));
        MentalListServices.deleteTips(this.props.id).then( res => {
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
            <Modal.Title>Delete Health Tip</Modal.Title>
          </Modal.Header>
          <Modal.Body>
              <Form.Group >
                  <div> Are you sure you want to delete {this.props.id}?</div>                  
              </Form.Group>
          </Modal.Body>
          <Modal.Footer>
              <Button variant="primary" type="submit" onClick={() => {this.deleteTips();}}>
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

export default MentalDeleteModal;