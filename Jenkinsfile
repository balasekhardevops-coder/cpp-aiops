pipeline {
    agent { label 'linux' }

    options {
        timestamps()
        timeout(time: 30, unit: 'MINUTES')
        skipDefaultCheckout(true)
    }

    stages {

        stage('Checkout') {
            steps {
                checkout scm
            }
        }

        stage('Verify Build Tools') {
            steps {
                sh '''
                    set -eu

                    gcc --version
                    g++ --version
                    cmake --version
                    ctest --version
                '''
            }
        }

        stage('CMake Configure') {
            steps {
                sh '''
                    cmake -S . -B build \
                        -DCMAKE_BUILD_TYPE=Release \
                        -DBUILD_TESTING=ON
                '''
            }
        }

        stage('Build') {
            steps {
                sh '''
                    cmake --build build \
                        --config Release \
                        --parallel 4
                '''
            }
        }

        stage('Unit Tests') {
            steps {
                sh '''
                    ctest --test-dir build \
                        -C Release \
                        --output-on-failure
                '''
            }
        }

        stage('Install Binaries') {
            steps {
                sh '''
                    cmake --install build \
                        --config Release \
                        --prefix "$WORKSPACE/package"
                '''
            }
        }

        stage('Package') {
            steps {
                sh '''
                    test -x package/bin/calculator

                    tar -czf cpp-release.tar.gz \
                        -C package .
                '''
            }
        }

        stage('Archive Artifact') {
            steps {
                archiveArtifacts(
                    artifacts: 'cpp-release.tar.gz',
                    fingerprint: true
                )
            }
        }
    }

    post {
        success {
            echo 'C++ Linux CI pipeline succeeded.'
        }

        failure {
            echo 'C++ Linux CI pipeline failed.'
        }

        always {
            cleanWs()
        }
    }
}
