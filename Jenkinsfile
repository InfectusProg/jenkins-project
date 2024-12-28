pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                git url: 'https://github.com/InfectusProg/jenkins-project.git', credentialsId: 'access_for_jenkins'
            }
        }

        stage('Build') {
            steps {
                script {
                    try {
                        bat '"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\MSBuild\\Current\\Bin\\MSBuild.exe" matiichyn-test.sln /p:Configuration=Debug /p:Platform=x64 /m'                    
                    } catch (Exception e){
                        echo "Build error: ${e.message}"
                        currentBuild.result = 'FAILURE'
                        error("Pipeline stopped due to build failure.")
                    }
                }
            }
        }

        stage('Test') {
            steps {
                script {
                    try {
                        bat '"D:\\lab4SP\\matiichyn-test\\x64\Debug\\matiichyn-test.exe"'                    
                    } catch (Exception e){
                        echo "Test error: ${e.message}"
                        currentBuild.result = 'FAILURE'
                        error("Pipeline stopped due to test execution failure.")
                    }
                }
            }
        }
    }

    post {
        always{
            cleanWs()
        }
        failure {
            echo 'Pipeline failed.'
        }
        success {
            echo 'Build and test succeeded!'
        }
    }
}
