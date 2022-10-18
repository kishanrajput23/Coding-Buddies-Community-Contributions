export class BookingDetails {

    public id:number=0;
    public driverName: string='';
    public userName: string ='';
    constructor(
    public source: string,
    public destination: string,
    public fare: Number,
    public carType:string,
    public userId: string,
    public driverId:string,
    public status: string,
    ){}
   

   
}
