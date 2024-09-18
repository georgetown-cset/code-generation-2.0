# code-generation-2.0
Repository for the CyberAI Code Generation Project

# Pipeline: 

<img width="712" alt="Screenshot 2024-08-02 at 12 01 12 PM" src="https://github.com/user-attachments/assets/fbf30e6d-78a8-459a-b2f8-07b1197593fa">

## The Model Evaluation Folder
- Contains a folder with the generated code snippets and ESBMC outputs for each model

## The Scripts Folder
- **esbmc_call.py**: calls the ESBMC model checker and runs it over the generated code folders
- **parse_esbmc.py**: functions that parse the ESBMC output
- **model-specific pipeline files**: runs the analysis pipeline for each of the model's outputs through ESBMC

## The Data Folder
- **summary_stats.ipynb**: summary statistics aggregated over all models
- **[model_name]_results.ipynb**: granular results for each model


