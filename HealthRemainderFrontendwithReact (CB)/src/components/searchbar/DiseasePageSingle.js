import React, { Component } from 'react';
import NavigationDiseaseSearch from '../navBars/NavigationDiseaseSearch';
import { Card } from "react-bootstrap";
class DiseasePageSingle extends Component {
    constructor(props) {
        super(props)

        this.state = {
            id:this.props.match.params.id,
            name:this.props.match.params.name,
            info:this.props.match.params.info,
            keys:this.props.match.params.keys
        }
    }
    render() {
        return (
            <>
            <NavigationDiseaseSearch />
            <div>
                <p>{" " }</p>
            </div>
            <Card className="text-center" style={{ width: '25rem', backgroundColor:'#D5F5E3', margin:'auto' }}>
                <Card.Header>Disease No. {this.state.id}</Card.Header>
                <Card.Body>
                    <Card.Title>{this.state.name}</Card.Title>
                    <Card.Text>
                    {this.state.info}
                    </Card.Text>
                </Card.Body>
                <Card.Footer className="text-muted">keywords: {this.state.keys}</Card.Footer>
                </Card>
            </>
        );
    }
}

export default DiseasePageSingle;