import './App.css';
import Body from './components/Body';
import Footer from './components/Footer';
import { BrowserRouter as Router,Route, Switch } from 'react-router-dom';
import Admin from './components/Admin';
import Patient from './components/Patient';
import Doctor from "./components/Doctor";
import AppointmentDetailsComponent from './components/crudpages/AppointmentDetailsComponent';
import DietInfoView from './components/crudpages/DietInfoView';
import MentalList from './components/crudpages/MentalList';
import DietList from './components/crudpages/DietList';
import DiseaseList from './components/crudpages/DiseaseList';
import Reminder from './components/Reminder';
import AllDoctorDetails from './components/crudpages/AllDoctorDetails';
import AllPatientDetails from './components/crudpages/AllPatientDetails';
import ViewAllSlots from './components/crudpages/ViewAllSlots';
import SearchPage from './components/searchbar/SearchPage';
import DiseasePageSingle from './components/searchbar/DiseasePageSingle';
import PatientProfileSet from './components/crudpages/PatientProfileSet';
import PatientProfileUpdate from './components/crudpages/PatientProfileUpdate';
import DoctorProfileCreate from './components/crudpages/DoctorProfileCreate';
import DoctorProfileUpdate from './components/crudpages/DoctorProfileUpdate'

function App() {
  return (    
    <div className="App">      
    <Router>
      <Switch >
        <Route exact path='/' component={Body} />
        <Route path='/admin' component={Admin}/>
        <Route path='/patient' component={Patient}/>
        <Route path='/doctor' component={Doctor}/>
        <Route path = "/viewAppointmentDetails/:type/:id" component = {AppointmentDetailsComponent}/>
        <Route path ="/viewInfo/:id/:name/:info/:keys" component ={DiseasePageSingle} />
        <Route exact path='/MentalList' component={MentalList}/>
        <Route exact path='/DietList' component={DietList}/>
        <Route exact path='/DiseaseList' component={DiseaseList}/>
        <Route exact path='/setreminder' component={Reminder}/>
        <Route exact path='/doctorList' component={AllDoctorDetails}/>
        <Route exact path='/patientList' component={AllPatientDetails}/>
        <Route path='/viewAllSlots' component={ViewAllSlots}/>
        <Route path='/searchpage' component={SearchPage}/>
        <Route path="/DietInfoView/:bmi" component={DietInfoView}/>
        <Route path="/PatientProfileSet" component={PatientProfileSet}/>
        <Route path="/PatientProfileUpdate/:id" component={PatientProfileUpdate}/>
        <Route path="/createDoc/" component={DoctorProfileCreate}/>
        <Route path="/updateDoc/:id" component={DoctorProfileUpdate}/>
      </Switch>
      
    
      <Footer/>
      </Router>
    </div>
  );
}

export default App;