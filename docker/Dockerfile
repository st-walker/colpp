FROM continuumio/anaconda3:5.0.1

# install sys requirements
RUN apt-get update
RUN apt-get install -y build-essential git

# clone in repo
RUN git clone https://github.com/st-walker/colpp

# update conda
RUN conda update --yes conda

# go into repo
RUN cd colpp && conda env create -f colpp-dev-requirements.yml

# activate
RUN echo "source activate colpp-dev-requirements" > ~/.bash
ENV PATH /opt/conda/envs/colpp-dev-requirements/bin:$PATH

# activate
#RUN conda activate colpp-dev-requirements

# make build dir
RUN cd colpp && mkdir build

# run cmake
RUN  cd colpp/build && \
    cmake .. -DCMAKE_INSTALL_PREFIX=$(conda info --base)/envs/colpp-dev-requirements

# build and install project
RUN cd colpp/build && \
    make -j2 install