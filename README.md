## *Effects of population density and environmental conditions on life-history prevalence in a migratory fish*  

#### *Ecology and Evolution*  

#### Mark H. Sorel, Andrew R. Murdoch, Rich W. Andrew, Cory M. Kamphaus, Eric R. Buhle, Mark D. Scheuerell, Sarah J. Converse  

##### Please contact the first author for questions about the code or data: Mark H. Sorel (marksorel8@gmail.com)  
_______________________________________________________________________________________

## Abstract

Individual variation in life-history traits can have important implications for the ability of populations to respond to environmental variability and change. In migratory animals, flexibility in the timing of life-history events, such as juvenile emigration from natal areas, can influence the effects of population density and environmental conditions on habitat use and population dynamics. We evaluated the functional relationships between population density and environmental covariates and the abundance of juveniles expressing different life-history pathways in a migratory fish, Chinook salmon (*Oncorhynchus tshawytscha*), in the Wenatchee River basin in Washington State, USA. We found that the abundance of younger emigrants from natal streams was best described by an accelerating or near-linear function of spawners, whereas the abundance of older emigrants was best described by a decelerating function of spawners. This supports the hypothesis that emigration timing varies in response to density in natal areas, with younger-emigrating life-history pathways comprising a larger proportion of emigrants when densities of conspecifics are high. We also observed positive relationships between winter stream discharge and abundance of younger emigrants, supporting the hypothesis that habitat conditions can also influence the prevalence of different life-history pathways. Our results suggest that early emigration, and a resultant increase in the use of downstream rearing habitats, may increase at higher population densities and with greater winter precipitation. Winter precipitation is projected to increase in this system due to climate warming. Characterizing relationships between life-history prevalence and environmental conditions may improve our understanding of species habitat requirements and is a first step in understanding the dynamics of species with diverse life-history strategies. As environmental conditions change -- due to climate change, management, or other factors -- resultant life-history changes are likely to have important demographic implications that will be challenging to predict if life-history diversity is not accounted for in population models.


## Table of Contents

-   *Archive* folder - contains old material not used in the paper

-   *data* folder - contains data used in the analysis

-   *Methods* folder - contains an appendix showing how a length-date cutoff rule was developed for classifying the age of juvenile emigrants.

-   *src* folder - contains r and TMB/c++ code for processing data, fitting models, and plotting results

    -   SR_all_LVM.R - This is the main controlling script for the analysis, which sources other scripts necessary to produce results.  
    -   Archive" - old material not used
    -   Chiwawa Data Proc 2.R - process screw trap catch and mark-recpature date
    -   covariates.R - process stremflow covariates
    -   Discharge data funcs.R - read streamflow data
    -   Load Screw Trap Data.R - read and compile screw trap catch and mark-recapture date
    -   mortality-migration-exampl - musings on modeling simultaneous mortality and migration. *Not used in manuscript*
    -   Nason White Data Proc 2.R - process screw trap catch and mark-recpature date for Nason and White River
    -   SR_helper_functions.R - helper functions for modeling of Beverton-Holt relationship between spawners and juveniles.
    -   SR_plotting_funcs_factor.R - plotting functions for Beverton-Holt relationship between spawners and juveniles.
    -   ST_all.R - main controlling script for fitting of Lincoln-Peterson emigrant abundance model to screw trap data.
    -   ST_helper_funcs.R - helper functions for fitting of Lincoln-Peterson model of emigrant abundance to screw trap data.
    -   ST_plotting_funcs.R - plotting functions for results of Lincoln-Peterson model of emigrant abundance to screw trap data.
    -   TMB
        -   screw_trap_LP_4.cpp - Lincoln-Peterson model of daily emigrant abundance

        -   Stock_recruit_LVM.cpp - Beverton-Holt model of relationship between spawners, juveniles, and streamflow
    -   ts_and_plotting_funcs.R - functions for plotting


## Required Packages and Versions Used

`R version 4.2.2`

`dataRetrieval_2.7.12` `glmmTMB_1.1.5` `readxl_1.4.1` `TMBhelper_1.4.0` `TMB_1.9.3` `viridis_0.6.2` `viridisLite_0.4.1` `lubridate_1.9.1` `forcats_1.0.0` `stringr_1.5.0` `dplyr_1.1.0` `purrr_1.0.1` `readr_2.1.2` `tidyr_1.3.0` `tibble_3.1.8` `ggplot2_3.4.1` `tidyverse_2.0.0` `here_1.0.1` `mixtools_2.0.0`


## How to use this repository
Start in the `SR_all_LVM.R` file. This file produces all results presented in the manuscript and sources other files in the repository. Those interested specifically in the estimation model for daily juvenile emigrant abundance and classification of life history pathways may want to start at the `src\ST_all.R` file.

Daily emigrant abundance estimation is accomplished using a Lincoln-Peterson model `src\TMB\screw_trap_LP_4.cpp`, and relationships with density and streamflow are evaluated using a modified Beverton-Holt model `src\TMB\Stock_recruit_LVM.cpp`.

