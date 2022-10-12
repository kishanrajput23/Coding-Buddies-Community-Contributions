import { Address } from "./address";
import { Facilites } from "./facilites";

export interface Hospital{
    id?:number;
    hospitalname:string;
    address:Address;
    faclites:Facilites;
}