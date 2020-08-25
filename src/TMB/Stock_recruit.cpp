#include <TMB.hpp>

template<class Type>
Type objective_function<Type>::operator() ()
{
  
  DATA_VECTOR(R_obs);                  // Observed log recruits (posterior mean from juvenile modle)
  DATA_VECTOR(R_obs_sd);               // Observed log recruits standard error (posterior mean from juvenile modle)
  DATA_VECTOR(S_obs);                  // Observed spawners (from redd counts)
  DATA_SCALAR(S_obs_cv);
  //DATA_SCALAR(S_obs_cv_hyper_mu);      // Hyper-mean for prior on spawner observation error
  //DATA_SCALAR(S_obs_cv_hyper_sd);      // Hyper-variance for prior spawner observation error
  DATA_INTEGER(Model);
  
  
 // PARAMETER(log_S_obs_cv);             //log spawner observation SD
  //Type S_obs_cv = exp(log_S_obs_cv);        
  //REPORT(S_obs_cv);
  PARAMETER_VECTOR(log_R_hat);    // latent true number of juveniles
  vector<Type> R_hat = exp(log_R_hat);
  REPORT(R_hat);
  //PARAMETER_VECTOR(log_R_obs_sd); // annual observation error of juveniles
  //vector<Type> R_obs_sd = exp(log_R_obs_sd);
  //REPORT(R_obs_sd);
  PARAMETER_VECTOR(log_S_hat);    // latent true number of spawners
  vector<Type> S_hat = exp(log_S_hat);
  REPORT(S_hat);
  PARAMETER(log_alpha);           // intrinsic productivity
  Type alpha =exp(log_alpha);
  REPORT(alpha);
  PARAMETER(log_R_max);           // Asymptotic maximum recruitment
  Type R_max =exp(log_R_max);
  REPORT(R_max);
  PARAMETER(log_proc_sigma);      // process error standard deviation
  Type proc_sigma = exp(log_proc_sigma);
  REPORT(proc_sigma);
  PARAMETER(log_d);
  Type d = exp(log_d);
  REPORT(d); 
 
//process models
 vector<Type> R_pred(S_obs.size());
   
 if(Model==1){
   R_pred= (alpha*S_hat)/(1+alpha*S_hat/R_max); //beverton-holt model
  REPORT(R_pred);
 }
 
 if(Model==2){
    R_pred= (R_max*pow(S_hat,d))/(alpha+pow(S_hat,d)); //Type III functional response
   REPORT(R_pred);
 }
 
 if(Model==3){
   R_pred= (R_max*pow(S_hat,alpha)); //power function
   REPORT(R_pred);
 }
 
 if(Model==4){
   R_pred= R_max*(1-exp(-(pow(S_hat/alpha,d)))); //weibull CDF
   REPORT(R_pred);
 }
 
 
 if(Model==5){
   R_pred= S_hat*(alpha); //linear
   REPORT(R_pred);
 }
 
 if(Model==6){
   R_pred= alpha*d*R_max*(1.0+exp(-1.0/d))*(S_hat/(d*R_max) - 
     log((1+exp((S_hat-R_max)/(d*R_max)))/(1.0+exp(-1.0/d)))); //smooth hockey stick?
   REPORT(R_pred);
 }
 
//likelihood

  Type state_Like=sum(dnorm(log(R_hat),
                             log(R_pred),
                             proc_sigma,
                             true));         //process likelihood

  vector<Type> resids = log(R_hat)-log(R_pred);
  REPORT(resids);
   
  // Type Prior_like_S_obs_var = dnorm (S_obs_cv, 
  //                                   S_obs_cv_hyper_mu,
  //                                   S_obs_cv_hyper_sd,
  //                                   true);
  // 
  
   Type Spawner_obs_like= sum(dnorm(log(S_hat),
                                     log(S_obs),
                                      S_obs_cv,
                                      true));    //observation likelihood (spawners)

  Type Recruit_obs_like= sum(dnorm(log(R_hat),
                                   R_obs,
                                   R_obs_sd,
                                   true));                   //Initialize observatin likelihood (recruits)

  // for (int Iyear=0; Iyear< S_obs.size() ;Iyear++){
  //   Recruit_obs_like+= sum(dnorm(log(vector<Type>(R_obs.col(Iyear))),
  //                                  log(R_hat(Iyear)),
  //                                  R_obs_sd(Iyear),true)); //Observatin likelihood (recruits)
  // }
  
  
  Type obj_fun = state_Like+ //Prior_like_S_obs_var+
    Spawner_obs_like+ Recruit_obs_like;
  REPORT(state_Like);
  REPORT(Spawner_obs_like);
  REPORT(Recruit_obs_like);
  REPORT(obj_fun);
  //REPORT(Prior_like_S_obs_var);
  ADREPORT(log_R_hat);
  ADREPORT(log_S_hat);
  return(-obj_fun);
}
